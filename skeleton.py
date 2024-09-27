import cv2
import numpy as np
from skimage.morphology import skeletonize
from scipy.ndimage import label

# Load the image in grayscale
image = cv2.imread('/Users/rakshitpant/Downloads/pic.jpeg', 0)

# Preprocess the image: Thresholding to binary
_, binary = cv2.threshold(image, 127, 255, cv2.THRESH_BINARY)
binary = 255 - binary  # Invert if necessary

# Skeletonization (using the Zhang-Suen thinning algorithm)
binary[binary == 255] = 1  # Normalize binary image
skeleton = skeletonize(binary).astype(np.uint8)

# Detect junctions and endpoints using morphological operations
kernel = np.ones((3, 3), np.uint8)

# Junctions: Points where 3 or more skeleton branches meet
junctions = cv2.filter2D(skeleton, -1, kernel)
junctions = (junctions >= 3).astype(np.uint8) * 255

# Endpoints: Points where only 1 branch ends
endpoints_kernel = np.array([[0, 0, 0], [0, 1, 0], [0, 0, 0]], dtype=np.uint8)
endpoints = cv2.filter2D(skeleton, -1, endpoints_kernel)
endpoints = ((endpoints == 1) & (skeleton == 1)).astype(np.uint8) * 255

# Label junctions and endpoints
num_junctions, labeled_junctions = label(junctions)
num_endpoints, labeled_endpoints = label(endpoints)

# Print skeleton structure (as an array)
print("Skeleton Structure Array (0s and 1s):")
print(skeleton)

# Print the number of junctions and endpoints
print(f"Number of Junctions: {num_junctions}")
print(f"Number of Endpoints: {num_endpoints}")

# Get and print the coordinates of junctions and endpoints
junction_coords = np.argwhere(labeled_junctions > 0)
endpoint_coords = np.argwhere(labeled_endpoints > 0)

print("Junction Coordinates (row, col):")
print(junction_coords)

print("Endpoint Coordinates (row, col):")
print(endpoint_coords)

# Show skeleton, junctions, and endpoints
cv2.imshow('Skeleton', skeleton * 255)
cv2.imshow('Junctions', labeled_junctions * 255)
cv2.imshow('Endpoints', labeled_endpoints * 255)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Save skeleton, junctions, and endpoints images
cv2.imwrite('/mnt/data/skeleton_image.png', skeleton * 255)
cv2.imwrite('/mnt/data/junctions_image.png', labeled_junctions * 255)
cv2.imwrite('/mnt/data/endpoints_image.png', labeled_endpoints * 255)