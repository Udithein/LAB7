#include <windows.h>
#include <gl/gl.h>
#include <math.h>

float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0};
float xAlfa = 20;
float zAlfa = 0;
POINTFLOAT pos ={0,0};
float pyramid[] = {0,0,2,  1,1,0,  1,-1,0,  -1,-1,0,  -1,1,0, 1,1,0};
float cord[]= {0,0,0, 3,0,0, 0,0,0, 0,3,0, 0,0,0, 0,0,3};
float vertex[]={-0.2,-0.2,0, 0.2,-0.2,0, 0.2,0.2,0, -0.2,0.2,0};

float kub[]={
-1,-1,0, 1,-1,0, 1,1,0, -1,1,0,
-1,-1,0, -1,1,0, -1,1,1, -1,-1,1
-1,1,0, -1,1,1, 1,1,1, 1,1,0,
-1,1,0, -1,1,1, 1,1,1, 1,1,0,
-1,-1,0, -1,-1,1, -1,1,1, -1,1,0
-1,-1,1, 1,-1,1, 1,1,1, -1,1,1
};

void Drow()
{
    glNormal3f(0,0,1);
    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,vertex);
        glDrawArrays(GL_TRIANGLE_FAN,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Draw_Cube(){
GLfloat vertices[] = {
 -0.5f, -0.5f, -0.5f,
 0.5f, -0.5f, -0.5f,
 0.5f, 0.5f, -0.5f,
 -0.5f, 0.5f, -0.5f,
 -0.5f, -0.5f, 0.5f,
 0.5f, -0.5f, 0.5f,
 0.5f, 0.5f, 0.5f,
 -0.5f, 0.5f, 0.5f
};
GLuint indices[] = {
 0, 1, 2,
 2, 3, 0,
 1, 5, 6,
 6, 2, 1,
 7, 6, 5,
 5, 4, 7,
 4, 0, 3,
 3, 7, 4,
 4, 5, 1,
 1, 0, 4,
 3, 2, 6,
 6, 7, 3
};

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, vertices);
glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);
glDisableClientState(GL_VERTEX_ARRAY);
}

void Draw_Figure(){

GLfloat vertices2[] = {
 -0.5, -0.68191, 2, //нижн€€+лева€ // 0
 -0.809017, 0.262866, 2, //верхн€€+ лева€ // 1
 0, 0.850651, 2, //сама€ верхн€€ // 2
 0.809017, 0.262866, 2, //верхн€€ + права€ // 3
 0.5, -0.68191, 2, //нижн€€ +права€ // 4

 -0.25429, -0.35, 1, // нижн€€ лева€ (маленький) // 5
 -0.41145, 0.133688, 1, //верхн€€ лева€(маленький)// 6
  0, 0.432624, 1, //сама€ верхн€€(маленький) //7
  0.41145, 0.133688, 1,// верхн€€ права€(маленький) //8
  0.25429, -0.35, 1, // нижн€€ права€(маленький) //9

 -0.5, -0.68191, 0, //нижн€€+лева€ // 10
 -0.809017, 0.262866, 0, //верхн€€+ лева€ // 11
 0, 0.850651, 0, //сама€ верхн€€ // 12
 0.809017, 0.262866, 0, //верхн€€ + права€ // 13
 0.5, -0.68191, 0, //нижн€€ +права€ // 14

};

GLuint indices2chet[] = {
 1, 2, 7, 6,
 2, 3, 8, 7,
 3, 8, 9, 4,
 9, 4, 0, 5,
 5, 0, 1, 6,

 10, 5, 9, 14,
 14, 9, 8, 13,
 13, 12, 7, 8,
 7, 6, 11, 12,
 11, 10,5, 6
};

GLuint indices2nechet1[] = {
 0, 1, 2, 3, 4, 0,
};
GLuint indices2nechet2[] = {
 6, 7, 8, 9, 5, 6
};
GLuint indices2nechet3[] = {
 10, 11, 12, 13, 14, 10
};

GLfloat normals2[] = {
 -0.5, -0.68191, 2, //нижн€€+лева€ // 0
 -0.809017, 0.262866, 2, //верхн€€+ лева€ // 1
 0, 0.850651, 2, //сама€ верхн€€ // 2
 0.809017, 0.262866, 2, //верхн€€ + права€ // 3
 0.5, -0.68191, 2, //нижн€€ +права€ // 4

 -0.25429, -0.35, 1, // нижн€€ лева€ (маленький) // 5
 -0.41145, 0.133688, 1, //верхн€€ лева€(маленький)// 6
  0, 0.432624, 1, //сама€ верхн€€(маленький) //7
  0.41145, 0.133688, 1,// верхн€€ права€(маленький) //8
  0.25429, -0.35, 1, // нижн€€ права€(маленький) //9

 -0.5, -0.68191, 0, //нижн€€+лева€ // 10
 -0.809017, 0.262866, 0, //верхн€€+ лева€ // 11
 0, 0.850651, 0, //сама€ верхн€€ // 12
 0.809017, 0.262866, 0, //верхн€€ + права€ // 13
 0.5, -0.68191, 0, //нижн€€ +права€ // 14
};

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, vertices2);

glEnableClientState(GL_NORMAL_ARRAY);
glNormalPointer(GL_FLOAT, 0, normals2);

glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, indices2nechet1);
glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, indices2nechet2);
glDrawElements(GL_POLYGON, 6, GL_UNSIGNED_INT, indices2nechet3);

glDrawElements(GL_QUADS, 40, GL_UNSIGNED_INT, indices2chet);

glDisableClientState(GL_VERTEX_ARRAY);
glDisableClientState(GL_NORMAL_ARRAY);

}

float i=0;

void Init_Material()
{
glEnable(GL_COLOR_MATERIAL); //разрешени€ использовани€
//материала
 glShadeModel(GL_SMOOTH); // сглаживает границы
 GLfloat material_ambient[] = { 0.2f, 0.2f, 0.2f, 0.5f };
 GLfloat material_diffuse[] = { 1.0f, 1.0f, 1.0f, 0.5f };
 GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 32.0f };
 GLfloat material_shininess[] = { 50.0f }; //блеск материала
 glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
 glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
 glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
 glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
}

void ShowWorld()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vert);
    glNormal3f(0,0,1);
    for (int i = -5; i<5; i++)
    for (int j = -5; j<5; j++)
        {
        glPushMatrix();
            if ((i+j)%2==0) glColor4f(0, 0.5, 0, 1);
            else glColor4f(1,1,1,1);
            glTranslatef(i*2, j*2, 0);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glPopMatrix();
        }
    glDisableClientState(GL_VERTEX_ARRAY);


    glPushMatrix();
        glTranslatef(4, 6 ,0.5);
        Init_Material();
        glColor4f(0.2,0,1, 0.1);
        Draw_Cube();
    glPopMatrix();

    glPushMatrix();
        glRotatef(i,0,1,0);
        i=i+0.5;

        float position[]={0,0,15,0};
        glLightfv(GL_LIGHT0,GL_POSITION, position);
        glTranslatef(0,0,15);

        glColor3f(1,1,1);
        Draw_Cube();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(0,-8,0);



    float a=1;
    for (int c = 0; c < 270; c+=45)
        {
            a-=0.15;
            glColor4f(1,0.5,0, a);
            glTranslatef(4*cos(c), 4*sin(c), 0);

            Init_Material();

            Draw_Figure();

        }

    glPopMatrix();

















}

void MoveCamera()
{
    if (GetKeyState(VK_UP) < 0) xAlfa = ++xAlfa > 180 ? 180 : xAlfa;
    if (GetKeyState(VK_DOWN) < 0) xAlfa = --xAlfa < 0 ? 0 :xAlfa;
    if (GetKeyState(VK_LEFT)<0) zAlfa++;
    if (GetKeyState(VK_RIGHT)<0) zAlfa--;

    float ugol = -zAlfa / 180 * M_PI;
    float speed = 0;
    if (GetKeyState('W')<0) speed = 0.1;
    if (GetKeyState('S')<0) speed = -0.1;
    if (GetKeyState('A')<0) { speed = 0.1; ugol -= M_PI*0.5; }
    if (GetKeyState('D')<0) { speed = 0.1; ugol += M_PI*0.5; }

    if(speed != 0)
    {
        pos.x +=sin(ugol)*speed;
        pos.y +=cos(ugol)*speed;
    }

    glRotatef(-xAlfa, 1,0,0);
    glRotatef(-zAlfa, 0,0,1);
    glTranslatef(-pos.x,-pos.y,-3);
}

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          800,
                          800,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1,0.1, -0.1,0.1, 0.2, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);



    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Init_Material();
    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix();
                MoveCamera();
                ShowWorld();
            glPopMatrix();

            SwapBuffers(hDC);

            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

