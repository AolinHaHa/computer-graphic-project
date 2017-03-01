# computer-graphic-project


3) Download the quat.cpp and quat.h, and implement the missing methods. Use the
results from 2) to test your implementation. Test the rotation method by computing a
rotation quaternion for a rotation about z by 30 degrees and then using it to rotate each
of the principal axis vectors (i.e. <1, 0, 0>, etc.)
4) (20 pts) Download the skeleton for the intersection of a ray and a polygon. You will
need to drop your versions of the point and vector classes (the project does not use the
matrix class). Then implement ray-polygon intersection. To do this, you will need to
perform the following steps. As you are writing your code, you can use the calculations
from problem 3 to check each step of the process.
a. Implement “CalculateNormal”. Your initial implementation can work with a
single try at the calculation that ignores the possibility of edges that are zero 
length or co-linear. But your final submission here should be the full version,
and you will check this in problem 5).
b. For a first shot at implementing the “Intersect” method. Make sure that you
can calculate the intersection of the ray with the plane. So, ignore the test for
whether the intersection point is in the polygon or not. The program will work,
except that when you move the ray off the polygon, the intersection point
won’t disappear.
c. Implement the full version where you test all the edges to see if the intersection
point is to the left of each edge. Your final version should have the intersection
point disappear as you move the ray off of each of the six polygon edges.
5) (10 pts) Change the Application.cpp implementation to build the following polygon.
Submit a working version of the project that tests this polygon with degenerate edges.
P = { (0, -1, -1), (0, -1, -1), (0, 0, -1), (0, 1, -1), (0, 1, 0), (0, 0, 1), (0, -1, 0) }
6) (15 points) Download the ray-trace skeleton project. For this problem, you will
complete two key sections of the ray-tracer, which will allow it to display scenes using
constant shading (each object will be drawn in a constant color). To complete this
problem, you will need to
a. Implement the “CastRay” method of the scene class. This method should loop
through the shapes in the scene and intersect the ray with each shape. It should
choose and return the intersection data for the closest intersection.
b. Complete the DrawScene method in the scene class. This method loops through
the pixels in the “on-screen” window and uses the method covered in class to
convert the coordinates into the “world” coordinates of the pixel. Then you
need to
i. form the ray from the camera to the pixel and then call “TraceRay” with
that ray.
ii. Trace ray will then call your implementation of cast ray, apply the
material and return a color.
iii. Since the only material in the current scene is a “constant material”, this
will simply return the color of the object.
Note that the code to actually set the pixel in the bitmap is already written for you. The
executable q1Raytrace.exe is a correctly working version of this program.
7) (10 points) Test your implementation of the ray-tracer by copying into the ray-trace
project the “Application.cpp” file for the “fakeMaterial” example. This material fakes
lighting, without actually having any lights in the scene by computing the dot product of
the normal at a ray intersection, with the view vector. The executable 02-
FakeMaterial.exe shows what the end result should look like.
8) (5 pts) Copy your implementation of the Polygon class from the earlier problem. Then
look at the end of the intersect method for the Sphere class. You can see that at the
end of the method, it copies a lot more data into the intersection object. You will need
to copy the same data into the intersection struct when you compute your ray-polygon 
intersection. Attach the same “fakeMaterial” to each object, as was attached to the
sphere in the last example. Your program should work like the 02a-FakeScene.
9) (10 points) Implement the lambertianMaterial’s “ReflectedColor method. This method
should calculate the ambient and diffuse reflectance from the surface given the
incoming light data in the “lightOutput” parameter. This light output parameter is a
struct that contains the direction from the surface to the light, and the light’s colors.
You will need to calculate
a. The forward-facing normal
b. The ambient reflectance taking into account both the surface color and the
ambient light color from the lightOutput data.
c. The diffuse reflectance taking into account the relationship between the light
and the normal. If the point is on the back-side of the surface with respect to
the light (how do you check this?) then the diffuse reflectance should be black.
Just like the simpler shaders, this should store the ambient and diffuse reflectance in the
“outA” and “outD” reference parameters.
10) (10 points) Implement the phongMaterial’s “ReflectedColor” method. Start by copying
the implementation of the lambertian material, and then adding the computation of the
specular reflectance, using the Phong reflectance formula. Note that if the intersection
point is on the back-side of the object, then there should be no specular reflectance as
well. Test your implementation on the “phong” scene in the scene files by copying up
the “Application.cpp” file into your project.
