#include <GL/glut.h>
#include <cmath>

int projectionMode = 0;

void drawPhoneBody() {
    glPushMatrix();
    glScalef(2.0, 4.0, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawScreen() {
    glPushMatrix();
    glTranslatef(0, 0.5, 0.11);
    glScalef(1.5, 2.5, 0.01);
    glColor3f(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawHomeButton() {
    glPushMatrix();
    glTranslatef(0, -1.7, 0.11);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

void drawSpeaker() {
    glPushMatrix();
    glTranslatef(0, 1.8, 0.11);
    glColor3f(0.3, 0.3, 0.3);
    glScalef(0.5, 0.1, 0.01);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawBackCamera() {
    glPushMatrix();
    glTranslatef(-0.5, 1.8, -0.11);
    glColor3f(0, 0, 0);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

void drawFlashLED() {
    glPushMatrix();
    glTranslatef(0.0, 1.8, -0.11);
    glColor3f(1.0, 1.0, 0.5);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();
}

void drawVolumeButtons() {
    glPushMatrix();
    glTranslatef(-1.05, 1.0, 0);
    glColor3f(0.3, 0.3, 0.3);
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.05, 0.4, 0);
    glColor3f(0.3, 0.3, 0.3);
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawPowerButton() {
    glPushMatrix();
    glTranslatef(1.05, 1.0, 0);
    glColor3f(0.3, 0.3, 0.3);
    glScalef(0.05, 0.5, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawBottomPortAndSpeaker() {
    glPushMatrix();
    glTranslatef(0, -2.0, -0.09);
    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.4, 0.05, 0.02);
    glutSolidCube(1.0);
    glPopMatrix();

    for (float x = -0.8; x <= 0.8; x += 0.2) {
        glPushMatrix();
        glTranslatef(x, -2.0, -0.09);
        glColor3f(0.2, 0.2, 0.2);
        glutSolidSphere(0.03, 10, 10);
        glPopMatrix();
    }
}

void drawPhone() {
    glColor3f(0.2, 0.2, 0.2);
    drawPhoneBody();
    drawScreen();
    drawHomeButton();
    drawSpeaker();
    drawBackCamera();
    drawFlashLED();
    drawVolumeButtons();
    drawPowerButton();
    drawBottomPortAndSpeaker();
}

void setProjection(int mode) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    switch (mode) {
        case 0: glOrtho(-3, 3, -3, 3, -10, 10); break;
        case 1: glOrtho(-3, 3, -3, 3, -10, 10); break; 
        case 2: glOrtho(-3, 3, -3, 3, -10, 10); break;
        case 3: glOrtho(-4, 4, -4, 4, -10, 10); break;
        case 4: glOrtho(-4, 4, -4, 4, -10, 10); break;
        case 5: glOrtho(-4, 4, -4, 4, -10, 10); break;
        case 6:
        case 7:
        case 8: gluPerspective(60.0, 1.0, 1.0, 20.0); break;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    switch (mode) {
        case 0: gluLookAt(0, 0, 5,  0, 0, 0,  0, 1, 0); break;
        case 1: gluLookAt(5, 0, 0,  0, 0, 0,  0, 1, 0); break;
        case 2: gluLookAt(0, 5, 0,  0, 0, 0,  0, 0, -1); break;
        case 3: gluLookAt(5, 5, 5,  0, 0, 0,  0, 1, 0); break;
        case 4: gluLookAt(5, 3, 5,  0, 0, 0,  0, 1, 0); break;
        case 5: gluLookAt(5, 2, 4,  0, 0, 0,  0, 1, 0); break;
        case 6: gluLookAt(0, 0, 5,  0, 0, 0,  0, 1, 0); break;
        case 7: gluLookAt(5, 0, 5,  0, 0, 0,  0, 1, 0); break;
        case 8: gluLookAt(5, 5, 5,  0, 0, 0,  0, 1, 0); break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    setProjection(projectionMode);
    drawPhone();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key >= '0' && key <= '8') {
        projectionMode = key - '0';
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.9, 0.9, 0.9, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Handphone 3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

