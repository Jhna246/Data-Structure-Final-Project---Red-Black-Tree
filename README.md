# Data-Structure-Final-Project---Red-Black-Tree

1. Implement a program which performs the following functions.
* The input file words.txt contains the English words of length five as specified in the
assigments
*  Build a red-black tree with the words specified in the file words.txt
* The input file cmd.txt, which is also called as the command file, contains multiple
lines. For each line, we perform the following operation.
– If the line is five letter words, it specifies search operation.
– If the first character of the line begins with - character, this line specifies delete
operation.
* For each search operation, print the search result
– If there is a preceding word, print it. Print NIL otherwise.
– Print the word itself
– If there is a suceeding word, print it. Print NIL otherwise.
* For each delete operation, delete the word in the red-black tree.
– If the word exists in the red-black tree, print a message that the word is deleted
– If the word doesn’t exist, print a message that the word isn’t in the red-black tree
* You don’t need to update the input file or create a separate output file

Example
Let’s assume that the input file words.txt contains the following

could
write
first
water
after
where

If you have seen a line with after in cmd.txt, the word exists, the succeeding word is
could. But there is no preceding word. Such that the output line for this operation looks like
the following.

NIL after could

If you have seen a line with comer, the word does not exists in the file the we can find the
succeeding and the preceding words for the word. Such that the output line for this operation
looks like the following.

after NIL could

Suppose that you have seen a line with about, the word does not exist and there is no preceding word. Therefore, the output line will look like the following.

NIL NIL after

Suppose that you have seen a line with -after, then the operation is delete. The output line
look like the following.

The "after" is deleted

After this delete operation, if you have seen a line after, the word is already deleted. Therefore, the output will become

NIL NIL could

Example For example, let’s assume that we have the input file words.txt as specified above
and the command file cmd.txt as follows.

after
comer
about
-after
after
The following is a simple output assuming that the project implemented in Java.
+---------------------------------------------------------------+
| $ java dsprj |
| NIL after could |
| after NIL could |
| NIL NIL after |
| The "after" is deleted |
| NIL NIL could |
+---------------------------------------------------------------+
