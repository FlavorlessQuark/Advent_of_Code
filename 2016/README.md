# Gotta go fast

## Reminder to self

Windows files have CRLF file endings and must be converted via `dos2unix [filename]`
Else some surprises may occur while parsing.

Interestingly after learning python, I look at file parsing differently >.<

Need to Update aoc.h:

Fetch by word by line ();
|               | Pros          	  | Cons  |
| ------------- |:-------------:	  | -----:|
| Array of list |easy to iterate **/** Only one call to malloc |Need to know line count beforehand **/** Potential need to read file twice **/** Not good for large files|
| Lists of list |Only one file read is enough |A pain to iterate through **/** Multiple calls to malloc **/** More pointers than I'd like|


**Need to check something about unallocated memory**

*If a list pointer *lst has an adress 0x000001 , is it valid to have another pointer *lst1 such that *lst1 = lst + sizeof(lst)?*
*Would 0x000009 be a valid adress ? Or does it need to be allocated?*
*I have to test this in the void_sandbox but I think it will either result in segfault or memory corruption over time...*

**Look into len and log**
