No code for this part.

Starting it by hand to understand how it works, there's a simple patterne. Basically moving any object 1 floor requires 2 moves. (First bring 2 object them move 1 back). However this last (bring one down) part doesn't need to be done for the last two objects (they can be brought together so it requires 1 move instead of 4).

We also need to minus some move for items that are already moved up one floor. In my input there was two items on floor 2 so I minus 4 moves

So for n amount of objects and f amount of floors, we need at minimum ((n * 2) - 3) * f - ((amount of objects on floor x  * 2) * (x - 1)

My input has 10 objects, 2 of which are on floor 2 and there is 4 floors. So this gives ((10 * 2) -3 ) * 4 - ((2 * 2) * 2 -1) = 37;

Part 2 adds 4 objects on floor 1 which gives ((14 * 2) -3 ) * 4 - ((2 * 2) * 2 -1) = 71;

I may code this solution evenutally. But math > code
