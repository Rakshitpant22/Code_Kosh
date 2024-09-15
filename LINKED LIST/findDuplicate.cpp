Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.

int findDuplicate(vector<int>& nums) {
       int slow=nums[0];
       int fast=nums[0];

        slow=nums[slow];
        fast=nums[nums[fast]]; //pehlehi +2 move kradia  wrna   while loop start hi nhi hoga

        while(slow!=fast){
           slow=nums[slow];//+1
           fast=nums[nums[fast]];//+2
       }
       //cycle detected send slow to start and fast ko 1 1 krke bdhao
       slow=nums[0];
       while(slow!=fast){
           slow=nums[slow];
           fast=nums[fast];
       }
       //jaha mile vo cycle ka starting hai
       return slow;  //fast
}


//* DO WHILE:
//~ Runs the loop at least once, because the condition is checked after the first iteration.

//* WHILE: 
//~ Runs the loop only if the condition is initially true; if slow == fast from the start, the loop will not run even once.

// we can implement above code by this way  also:   USING DO WHILE LOOP

       int slow=nums[0];
       int fast=nums[0];
      do
      {
        slow=nums[slow];
        fast=nums[nums[fast]];
      } while (slow!=fast);
      
       slow=nums[0];
       while(slow!=fast){
           slow=nums[slow];
           fast=nums[fast];
       }
       return slow;  