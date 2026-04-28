# Analysis and Doubts Resolution: `hand.ino`

### 1. The purpose of the `setup()` function
**Your comment:** *"The setup function in archives of the .ino extension are so the variables are declarated."*
**Correction:** This is a common misconception. In Arduino (C++), global variables (like `Servo servoPulgar;`) are declared *outside* and *before* the `setup()` function. The actual purpose of `setup()` is **initialization**. It runs only once when the board powers on, and it is used to configure the environment: assigning pins (using `attach()` or `pinMode()`), starting serial communication, or setting initial states. 

### 2. Asymmetric servo angles (70 to 145 vs. 130 to 55)
**Your comment:** *"It is a bit strange that there are 75 steps but it is being added to 70... so it finishes in 145 degrees."* & *"That the closing of the hand starts in 70 or 75 but when it relaxes goes all the way up to 55 is more strange still."*
**Explanation:** Your observation is spot on. In a perfect simulation, a servo would go from 0 to 180. However, in physical robotics, this asymmetry is entirely normal. It exists to compensate for the physical limitations of the 3D-printed hand, the mechanical tension of the strings pulling the fingers, and how the servos were physically mounted. Pushing a servo past its mechanical limit (e.g., forcing it to 0 or 180 when the string is already fully tight) would overheat and burn the motor. 

### 3. Finer control using `writeMicroseconds()` vs `write()` & The `map()` function
**Your research summary:** You investigated and found that `writeMicroseconds()` provides finer control over the motor than `write()`. `write()` only allows 0-180 (180 discrete steps), while `writeMicroseconds()` usually operates between 1000 and 2000 (1000 discrete steps).
**Explanation on how `map()` works:** Since your loop counter `i` only goes from 0 to 75, you can't pass `i` directly into `writeMicroseconds()`. The `map(value, fromLow, fromHigh, toLow, toHigh)` function acts as a proportional translator. It takes your `i` (which ranges from 0 to 75) and mathematically stretches it to fit the 1000 to 2000 range. For example, when `i = 0`, it outputs 1000. When `i = 37.5` (halfway), it outputs 1500.

### 4. Sequential execution vs. Simultaneous illusion
**Your comment:** *"While these instructions are written secuentially, the computer is that fast that it creates the 'illusion' that each finger is moving at the same time."*
**Explanation:** Correct. The Arduino evaluates each `write` command in microseconds. By the time it hits the `delay(7)` at the end of the loop, all servos have received their new position command virtually simultaneously. 

### 5. Using a flag variable for optimization
**Your comment:** *"I think this logic could have been greatly simplified simply by using a flag variable that automatically multiplies by -1 to the servos who are running in the opposite direction..."*
**Explanation:** This is a brilliant optimization idea. Instead of hardcoding addition (`+ i`) for some fingers and subtraction (`- i`) for others across different loops, you can assign a direction multiplier (1 or -1) to each finger. This reduces code duplication significantly. (See the `hand_alt.ino` file for the implementation of your idea).