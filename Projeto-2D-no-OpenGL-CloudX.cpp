#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
float Ty = 0.0;
float Tx = 0.0;
float Tr = 0.0;
float Cr = 0.300;//cor nova do quadrado
float Cg = 0.100;
float Cb = 0.50;
float Px = 0.0;
float Telhadox = 0.0;


//void Quadrado(float iX, float iY) {
void Quadrado() {
    glBegin(GL_QUADS);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.50, 0.0);
    glVertex2f(0.50, -0.3);
    glVertex2f(0.1, -0.3);
    glEnd();
}

void Chao() {
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex2f(-1.0, -0.6);
    glVertex2f(-1.0, -1.5);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -1.5);
    glEnd();
}


void Porta() {
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.1f, 0.0f);
    glVertex2f(0.4, -0.6);
    glVertex2f(0.4, -0.3 + Px);
    glVertex2f(0.5 + Px, -0.3 + Px);
    glVertex2f(0.5 + Px, -0.6);
    glEnd();
}

void Janela1() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.7, -0.1);
    glVertex2f(0.8, -0.1);
    glVertex2f(0.8, -0.2);
    glVertex2f(0.8, -0.3);
    glVertex2f(0.7, -0.3);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, -0.1);
    glEnd();
}

void MeioJanela() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.7, -0.1);
    glVertex2f(0.7, -0.3);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.8, -0.2);

    glEnd();
}




 



void DrawCircle1()
{GLfloat ballRadius = .1f;//tamanho do circulo   
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(.84f, .153f,.199f); // cor do circulo
      glVertex2f(0.0f, 0.0f);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * M_PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
      }
   glEnd();
}

void DrawCircle2()
{GLfloat ballRadius = .1f;//tamanho do circulo   
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0f, 1.0f, 0.0f); // cor do circulo
      glVertex2f(0.0f, 0.0f);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * M_PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
      }
   glEnd();
}
// Fun????o callback chamada para fazer o desenho
void Desenha()
{

    //Limpa a janela de visualiza????o com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);


    //DESENHA A ESTRELA
  //  glPushMatrix();
  //  glColor3f(1.0f, 1.0f, 0.0f);
   // glScalef(0.2, 0.2, 0);
   // glTranslated(3, 3, 0.0);
   // Estrela();
  //  glPopMatrix();


    // DESENHA O SOL
   // glPushMatrix();
    //glScalef(0.1, 0.1, 0);
    //glTranslatef(-5, 6, 0);
   // glRotated(Tr, 0, 0, 1);
    //DrawCircle();
    //glPopMatrix();


    // DESENHA/
    glPushMatrix();
    Chao();
    glColor3f(Cr, Cg, Cb);
    glTranslated(Tx, Ty, 0.0);
    Quadrado();
     glRotated(Tr, 0, 0, 1);
    DrawCircle1();
    glTranslated(0.3, 0.1, 0.0);//aqui deixa ele em cima do quadrado
    DrawCircle2();
    glPopMatrix();

    glFlush();
}

// Inicializa par??metros de rendering
void Inicializa(void)
{

    // Define a cor de fundo da janela de visualiza????o como preta
    glClearColor(0, 0.5, 0.75, 0);

}

void teclado(unsigned char tc, int x, int y) {
    //tc <- qual tecla foi seleciodana no teclado
    // x e y <- s??o as posi????es do mouse quando a tecla foi selecionada
    switch (tc) {
    case 'a':
        //Tx -= 0.2;
        Px += 0.005;
        break;
    case 's':
        //Tx -= 0.2;
        Px -= 0.005;
        break;
    case 'd': // Telahado desce
        Telhadox += 0.010;
        break;
    case 'f': // Telhado sobe
        Telhadox -= 0.010;
        break;
    case 'r':
        Tr += 50;
        break;
    case 't':
        Tr -= 50;
        break;
    default:
        break;
    }
    //Renderiza a tela
    glutPostRedisplay();
}

void teclaEspecial(int ts, int x, int y) {
    //tc <- qual tecla foi seleciodana no teclado
    // x e y <- s??o as posi????es do mouse quando a tecla foi selecionada
    switch (ts) {
    case GLUT_KEY_UP:
        Ty += 0.1;
        Tr+=50;
        break;
    case GLUT_KEY_DOWN:
        Ty -= 0.1;
        Tr+=50;
        break;
    case GLUT_KEY_RIGHT:
        Tx += 0.2;
		;Tr+=50;
        break;
    case GLUT_KEY_LEFT:
        Tx -= 0.2;
		Tr+=50;
        break;
    default:
        break;
    }
    //Renderiza a tela
    glutPostRedisplay();
}

void MouseM(int botao, int estadoB, int x, int y) {
    if (botao == GLUT_LEFT_BUTTON) {
        if (estadoB == GLUT_DOWN)
            if (Cr == 1) {
                Cr = 0.3;
                Cg = 1.0;
                Cb = 0.4;
            }
            else if (Cg == 1.0) {
                Cr = 0.3;
                Cg = 0.5;
                Cb = 1.0;
            }
            else if (Cb = 1.0) {
                Cr = 1.0;
                Cg = 0.6;
                Cb = 0.2;
            }

    }

    //Renderiza a tela
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("CLOWN HOUSE");

    glutDisplayFunc(Desenha);

    //Intera????o com o TECLADO
    glutKeyboardFunc(teclado);

    //Intera????o com o TECLADO - Teclas especiais do teclado
    glutSpecialFunc(teclaEspecial);

    //Intera????o com o MOUSE
    glutMouseFunc(MouseM);

    Inicializa();
    glutMainLoop();

    return 0;
}
