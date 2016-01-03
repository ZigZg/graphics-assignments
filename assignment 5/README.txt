1. I compiled my code by cding into the build folder (using "cd build", if already in the starter4 folder) and running "make install" to compile the code.

2. I didn't collaborate with anyone for this assignment.

3. I used cplusplus.com for C++ reference, as well as Stack Overflow for debugging unknown coding errors.

4. Everything works, except the colors in the output files in some cases are brighter than the solutions (see the images/a5 directory). Most notable are test case 10, in which there's a very bright patch at the top of the big sphere that isn't in the solution, and test case 12, where the vase is quite brighter than the solution. I've gone through several reasons for why this could be, but I have yet to figure it out. I have a feeling that it has to do with the paths the rays are taking (perhaps the ray tree is being traversed incorrectly), but I would need more time to sit down and figure it out.

5. No extra credit

6. While there were definitely more difficult bugs to deal with, I found this assignment to be very entertaining, and certainly a good preparation for what I plan to do for my final project!

Final Project Proposal
	For the final project, I plan on implementing a simulation of a rotating strobe crystal light (see the cited url below for an example). The 3D mesh would be composed of a solid base which would contain a multi-colored light source, and the base would also hold a rotating crystal-like object on top of it. The light source would shine through this crystal, illuminating the surrounding environment with a certain light pattern. As it stands, I will be working alone on this assignment.

Here are the steps I plan on taking for implementing this:
1. I plan on using primitives and obj files to generate the mesh file, and will use ray casting code to render it.
2. The light source will be specified in an outside file (similar to those of the assignments), and I will use ray tracing code to render the effects of the light shining through the crystal.
3. I plan on writing code to animate the rotation of the crystal, as well as implement the updating of the lights as the crystal moves.
4. If time allows, I may implement the ability to support more than one light source, and perhaps have objects (reflective, refractive, or otherwise) surrounding the light to further interact with the light beams. If I still have time after this (unlikely, but possible), I may even implement user interaction functionality, such as having a user be able to move any object in the scene, change the camera angle, and/or change the color/intensity of the lights.


References
http://www.amazon.com/Lightahead%C2%AE-Rotating-Strobe-Crystal-changing/dp/B00AMUP9XG/ref=br_lf_m_1001097941_1_1_ttl?ie=UTF8&s=hi&pf_rd_p=2244081642&pf_rd_s=center-3&pf_rd_t=1401&pf_rd_i=1001097941&pf_rd_m=ATVPDKIKX0DER&pf_rd_r=11CWBSZ487MQ57TFF33W
