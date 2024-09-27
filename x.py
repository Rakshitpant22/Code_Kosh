import cv2
import numpy as np
from skimage.morphology import skeletonize
import random
import os

def remove_non_green(image):
    # Convert the image to HSV
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    
    # Define range for green color in HSV
    lower_green = np.array([35, 40, 40])
    upper_green = np.array([85, 255, 255])
    
    # Mask for green color
    mask = cv2.inRange(hsv, lower_green, upper_green)
    result = cv2.bitwise_and(image, image, mask=mask)
    
    return result

def binarize_image(image):
    # Convert image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Apply Otsu's thresholding
    _, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    
    return binary

def skeletonize_image(binary_image):
    # Skeletonization using scikit-image
    skeleton = skeletonize(binary_image // 255)  # Normalize binary to 0, 1
    skeleton = np.uint8(skeleton) * 255  # Convert back to 0, 255 format for OpenCV compatibility
    
    return skeleton

def random_color():
    return [random.randint(0, 255) for _ in range(3)]

def find_leaf_nodes_and_tips(skeleton):
    # Detecting leaf-tip (endpoints) and leaf-junctions (branch points)
    endpoints = []
    junctions = []
    
    # Iterate through the skeleton to find neighbors for each point
    for y in range(1, skeleton.shape[0] - 1):
        for x in range(1, skeleton.shape[1] - 1):
            if skeleton[y, x] == 255:
                neighbors = skeleton[y-1:y+2, x-1:x+2]
                neighbor_count = np.sum(neighbors == 255) - 1  # Exclude the center pixel
                if neighbor_count == 1:
                    endpoints.append((x, y))  # Leaf-tip
                elif neighbor_count > 2:
                    junctions.append((x, y))  # Leaf-junction
                    
    return endpoints, junctions

def mark_leaves(image, skeleton, endpoints, junctions):
    leaf_sizes = []
    marked_image = image.copy()
    
    for tip in endpoints:
        current_point = tip
        leaf_length = 0
        path = []
        
        # Traverse from tip to junction along the skeleton
        while current_point not in junctions:
            path.append(current_point)
            x, y = current_point
            
            # Check 8-connected neighborhood
            neighbors = [(x-1, y-1), (x, y-1), (x+1, y-1),
                         (x-1, y),           (x+1, y),
                         (x-1, y+1), (x, y+1), (x+1, y+1)]
            
            next_point = None
            for nx, ny in neighbors:
                if 0 <= nx < skeleton.shape[1] and 0 <= ny < skeleton.shape[0]:
                    if skeleton[ny, nx] == 255 and (nx, ny) not in path:
                        next_point = (nx, ny)
                        break
            
            if next_point:
                current_point = next_point
                leaf_length += 1
            else:
                break
        
        leaf_sizes.append(leaf_length)
        
        # Mark the leaf with random color
        color = (0, 255, 255)
        for point in path:
            cv2.circle(marked_image, point, 1, color, -1)
        
        # Display leaf size
        if path:
            midpoint = path[len(path) // 2]
            cv2.putText(marked_image, str(leaf_length), midpoint, cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1, cv2.LINE_AA)
    
    return marked_image, leaf_sizes


def find_and_draw_contours(image, binary_image):
    # Find contours in the binary image
    contours, _ = cv2.findContours(binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Draw contours on the image
    contour_image = image.copy()
    cv2.drawContours(contour_image, contours, -1, (0, 255, 255), 2)  # Draw all contours in green
    
    return contour_image, contours


# Load the original plant image from storage
image_path = os.path.join('/Users/rakshitpant/Downloads/pic.jpeg')  # Update with your image path
image = cv2.imread(image_path)

if image is None:
    print("Error: Image not found. Please check the file path.")
else:
    # Step 1: Extract foreground by removing non-green pixels
    foreground = remove_non_green(image)

    # Step 2: Binarize the extracted foreground
    binary_image = binarize_image(foreground)

    # Step 3: Skeletonize the binary image
    skeleton = skeletonize_image(binary_image)

    # Step 4: Detect leaf-tip and leaf-junctions
    endpoints, junctions = find_leaf_nodes_and_tips(skeleton)

    # Step 5: Mark leaves, calculate size, and display
    marked_image, leaf_sizes = mark_leaves(foreground, skeleton, endpoints, junctions)

    # Step 6: Find and draw contours
    contour_image, contours = find_and_draw_contours(foreground, binary_image)

    # Show output
    cv2.imshow('Original Image', image)
    cv2.imshow('Foreground', foreground)
    
    cv2.imshow('Binary image',binary_image)
    cv2.imshow('Skeleton', skeleton)
    cv2.imshow('Marked Leaves', marked_image)
    cv2.imshow('Contours', contour_image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

    # Output leaf sizes and contour info
    print("Leaf Sizes (in pixels):", leaf_sizes)
    print(f"Number of contours detected: {len(contours)}")