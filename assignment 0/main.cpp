#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <vecmath.h>
#include <string>
using namespace std;

// Globals

// This is the list of points (3D vectors)
vector<Vector3f> vecv;

// This is the list of normals (also 3D vectors)
vector<Vector3f> vecn;

// This is the list of faces (indices into vecv and vecn)
// Explanation of format of vecf's contents is in assignment handout, under
// section 2.3, "Mesh Loading and Display"
vector<vector<unsigned> > vecf;


// You will need more global variables to implement color and position changes
int colorcounter = 0;
float lightX = 1.0f;
float lightY = 1.0f;
int MAX_BUFFER_SIZE = 0x10000;

// These are convenience functions which allow us to call OpenGL 
// methods on Vec3d objects
inline void glVertex(const Vector3f &a) 
{ glVertex3fv(a); }

inline void glNormal(const Vector3f &a) 
{ glNormal3fv(a); }


// This function is called whenever a "Normal" key press is received.
void keyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27: // Escape key
        exit(0);
        break;
    case 'c':
        // color-changing code
		colorcounter += 1; 
        break;
    default:
        cout << "Unhandled key press " << key << "." << endl;        
    }

	// this will refresh the screen so that the user sees the color change
    glutPostRedisplay();
}

// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc( int key, int x, int y )
{
    switch ( key )
    {
    // changes the light position
    case GLUT_KEY_UP:
		lightY += 0.5f;
		break;
    case GLUT_KEY_DOWN:
		lightY -= 0.5f;
		break;
    case GLUT_KEY_LEFT:
		lightX -= 0.5f;
		break;
    case GLUT_KEY_RIGHT:
		lightX += 0.5f;
		break;
    }

	// this will refresh the screen so that the user sees the light position
    glutPostRedisplay();
}

// This function is responsible for displaying the object.
void drawScene(void)
{
    int i;

    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Rotate the image
    glMatrixMode( GL_MODELVIEW );  // Current matrix affects objects positions
    glLoadIdentity();              // Initialize to the identity

    // Position the camera at [0,0,5], looking at [0,0,0],
    // with [0,1,0] as the up direction.
    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // Set material properties of object

	// Here are some colors you might use - feel free to add more
    GLfloat diffColors[4][4] = { {0.5, 0.5, 0.9, 1.0},
                                 {0.9, 0.5, 0.5, 1.0},
                                 {0.5, 0.9, 0.3, 1.0},
                                 {0.3, 0.8, 0.9, 1.0} };
    
	// Here we use the color counter to select the corresponding entry as the diffuse color
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffColors[colorcounter % 4]);

	// Define specular color and shininess
    GLfloat specColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {100.0};

	// Note that the specular color and shininess can stay constant
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  
    // Set light properties

    // Light color (RGBA)
    GLfloat Lt0diff[] = {1.0,1.0,1.0,1.0};
    // Light position
	GLfloat Lt0pos[] = {lightX, lightY, 5.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

	// This GLUT method draws a teapot.  You should replace
	// it with code which draws the object you loaded.
	//glutSolidTeapot(1.0);
    
    // object-loading code
    for (unsigned int j=0; j < vecf.size(); j++) {
        // indices for vecv and vecn
        unsigned a = vecf[j][0];
        unsigned c = vecf[j][1];
        unsigned d = vecf[j][2];
        unsigned f = vecf[j][3];
        unsigned g = vecf[j][4];
        unsigned i = vecf[j][5];

        //draws the face's vertices and corresponding normals
        glBegin(GL_TRIANGLES);
        glNormal3d(vecn[c-1][0], vecn[c-1][1], vecn[c-1][2]);
        glVertex3d(vecv[a-1][0], vecv[a-1][1], vecv[a-1][2]);
        glNormal3d(vecn[f-1][0], vecn[f-1][1], vecn[f-1][2]);
        glVertex3d(vecv[d-1][0], vecv[d-1][1], vecv[d-1][2]);
        glNormal3d(vecn[i-1][0], vecn[i-1][1], vecn[i-1][2]);
        glVertex3d(vecv[g-1][0], vecv[g-1][1], vecv[g-1][2]);
        glEnd();
    }
    
    // Dump the image to the screen.
    glutSwapBuffers();


}

// Initialize OpenGL's rendering modes
void initRendering()
{
    glEnable(GL_DEPTH_TEST);   // Depth testing must be turned on
    glEnable(GL_LIGHTING);     // Enable lighting calculations
    glEnable(GL_LIGHT0);       // Turn on light #0.
}

// Called when the window is resized
// w, h - width and height of the window in pixels.
void reshapeFunc(int w, int h)
{
    // Always use the largest square viewport possible
    if (w > h) {
        glViewport((w - h) / 2, 0, h, h);
    } else {
        glViewport(0, (h - w) / 2, w, w);
    }

    // Set up a perspective view, with square aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 50 degree fov, uniform aspect ratio, near = 1, far = 100
    gluPerspective(50.0, 1.0, 1.0, 100.0);
}

void loadInput()
{
	// load the OBJ file here
    char buffer[MAX_BUFFER_SIZE];
    while (cin.getline(buffer, MAX_BUFFER_SIZE)) {
        stringstream ss(buffer);
        string s;
        ss >> s;
        // if a vertex
        if (s == "v") {
            Vector3f v;
            ss >> v[0] >> v[1] >> v[2];
            vecv.push_back(v);
        // else if a normal
        } else if (s == "vn") {
            Vector3f v;
            ss >> v[0] >> v[1] >> v[2];
            vecn.push_back(v);
        // else if a face
        } else if (s == "f") {
            // contains the indices into vecv and vecn (6 in total)
            vector<unsigned> v;
            Vector3f values;
            //each of the elements is of the format "a/b/c"
            ss >> values[0] >> values[1] >> values[2];
            for (unsigned int i=0; i < values.size(); i++) {
                //parses and selects the first and last integers of each element (i.e. "a" and "c")
                string value = values[i];
                string delim = "/";
                int first = value.find(delim);
                string a = value.substr(0, first);
                int last = value.rfind(delim);
                string b = value.substr(last+1, value.length()-last-1);
                v.push_back(stoul(a));
                v.push_back(stoul(b));
            }
            vecf.push_back(v);
        }
    }
}

// Main routine.
// Set up OpenGL, define the callbacks and start the main loop
int main( int argc, char** argv )
{
    loadInput();

    glutInit(&argc,argv);

    // We're going to animate it, so double buffer 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // Initial parameters for window position and size
    glutInitWindowPosition( 60, 60 );
    glutInitWindowSize( 360, 360 );
    glutCreateWindow("Assignment 0");

    // Initialize OpenGL parameters.
    initRendering();

    // Set up callback functions for key presses
    glutKeyboardFunc(keyboardFunc); // Handles "normal" ascii symbols
    glutSpecialFunc(specialFunc);   // Handles "special" keyboard keys

     // Set up the callback function for resizing windows
    glutReshapeFunc( reshapeFunc );

    // Call this whenever window needs redrawing
    glutDisplayFunc( drawScene );

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop( );

    return 0;	// This line is never reached.
}