#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float gerakhitung = 0;
int pause = 0;
int c = 0;
int p = 2;
float ax=41 ,ay= 0, bx=0 ,by=45, cx=-50 ,cy=-50;

void init(){
glClearColor(1, 1, 1, 0);
glMatrixMode(GL_PROJECTION);//Fungsi mode proyeksi
glLoadIdentity();//mendifinisikan objek
glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

void nrp(){
glClear(GL_COLOR_BUFFER_BIT);

//kotax
    glBegin(GL_POLYGON);
    glColor3f(c,c,1);
    glVertex2f(1+ax, 0.5+ay);
    glVertex2f(1+bx, 0.5+by);
    glVertex2f(1+cx, 0.5+cy);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(ax,2+ay);
    glVertex2f(2+ax,2+ay);
    glVertex2f(2+ax, ay);
    glVertex2f(ax, ay);
    glEnd ();
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(bx,2+by);
    glVertex2f(2+bx,2+by);
    glVertex2f(2+bx, by);
    glVertex2f(bx, by);
    glEnd ();

glBegin(GL_QUADS);
     glColor3f(1,0,0);
    glVertex2f(cx,2+cy);
    glVertex2f(2+cx,2+cy);
    glVertex2f(2+cx, cy);
    glVertex2f(cx, cy);
    glEnd ();

glPopMatrix();//kembali ke koordinat sebelum dipush

glPushMatrix();//Fungsi untuk menyimpan nilai matrix

glEnd();

glutSwapBuffers();//Fungsi perpindahan
}

void timer(int t){
    if (gerakhitung<95){
        ay += 0;
        ax -= 1;
        by -= 1;
        bx += 0;
        cy +=1;
        cx +=1;
        gerakhitung +=1;
        pause+=1;
}
else if (gerakhitung<190){
        ay += 0;
        ax += 1;
        by += 1;
        bx += 0;
        cy -=1;
        cx -=1;
        gerakhitung +=1;
        pause+=1;
    }


     else if (gerakhitung<191){
        ax=41;
        ay= 0;
        bx=0;
        by=45;
        cx=-50 ;
        cy=-50;
        gerakhitung =0;
        pause =0;
    }
 glutPostRedisplay();
glutTimerFunc(35,timer,0);

}

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT);
    nrp();
    glFlush();
}

void kb( unsigned char key, int x, int y ){
if (p%2==0){
    c=1;
}
if(p%2 !=0){
 c = 0;
}
if (key=='c'){
        p +=1;
}
}

int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(640, 480); // ukuran window
glutInitWindowPosition(100, 100); // posisi window
glutCreateWindow("Tugas4 asdos 672018219");
init();
glutKeyboardFunc(kb);
glutDisplayFunc(tampil); //tampilan rendernya
glutTimerFunc(1,timer,0);
glutMainLoop();
return 0;
}
