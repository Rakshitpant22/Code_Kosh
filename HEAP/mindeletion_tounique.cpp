A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.
The frequency of a character in a string is the number of times it appears in the string. For example, 
in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

approach 1::

freq_ wise map m store krdo,
fir map ki freq max heap m daldo:,
jabtak(pq ka size ==1 nhi hojata ){
    x=pq.top();
    pq.pop();
agr ab freq ab vale top == x ke barabar to deltions cnt bdhado;
or pq m push(x-1);
}

last m deltions cnt return krdo::


