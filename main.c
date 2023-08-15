
#include "modelo.c"
#include <stdlib.h>
#include <string.h>

int window;

// Matriz para armazenar os ângulos de caminhada
float caminhar_angulos[2][6];

// Variável para controlar o movimento base
double movimento_base = 0.0;

// Variáveis para armazenar as angulações das articulações
shoulder1 = 0;
elbow1 = 0;
shoulder2 = 0;
elbow2 = 0;
leg11=0;
leg12=0;
leg21=0;
leg22=0;
head=0;

// Angulações das articulações das pernas, câmera e zoom
float angulo_virilhaE = 30,
      angulo_joelhoE = 0,
      angulo_virilhaD = -30,
      angulo_joelhoD = 0,
      zoom = 1.0;

int rotacaox = 0,	rotacaoy = 0;


// Função para desenhar texto na tela
void drawText(const char *text, float x, float y) {
    glRasterPos2f(x, y);
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Função chamada quando um item do menu é selecionado
void menu_select(int mode) {
    switch (mode) {
        case 4:
            exit(EXIT_SUCCESS);
    }
}

// Função vazia para itens de menu sem ação
void null_select(int mode) {}

void glutMenu(void){
    int glut_menu[10];
    glut_menu[1] = glutCreateMenu(null_select);
    glutAddMenuEntry("Move Braço (e/D) : s,S", 0);
    glutAddMenuEntry("Move Antebraço (F/T) : e,E", 0);

    glut_menu[2] = glutCreateMenu(null_select);
    glutAddMenuEntry("Move Braço (e/D) : d,D", 0);
    glutAddMenuEntry("Move Antebraçoo (F/T) : f,F", 0);

    glut_menu[4] = glutCreateMenu(null_select);
    glutAddMenuEntry("Move a Perna (e/D) : l,L", 0);
    glutAddMenuEntry("Move a Canela (e/D) : m,M", 0);

    glut_menu[5] = glutCreateMenu(null_select);
    glutAddMenuEntry("Move a Perna (e/D) : n,N", 0);
    glutAddMenuEntry("Move a Canela (e/D) : o,O", 0);

    glut_menu[6] = glutCreateMenu(null_select);
    glutAddMenuEntry("'H' para a Esquerda", 0);
    glutAddMenuEntry("'h' para a Direita", 0);

    glut_menu[3] = glutCreateMenu(NULL);
    glutAddSubMenu("Perna Esquerda", glut_menu[4]);
    glutAddSubMenu("Perna Direita", glut_menu[5]);

    glut_menu[0] = glutCreateMenu(null_select);
    glutAddSubMenu("Braço 1", glut_menu[1]);
    glutAddSubMenu("Braço 2", glut_menu[2]);

    glut_menu[7] = glutCreateMenu(null_select);
    glutAddMenuEntry("Use as Setas", 0);

    glut_menu[8] = glutCreateMenu(null_select);
    glutAddMenuEntry("PRESSIONE 'a' para ANDAR", 0);

    glut_menu[9] = glutCreateMenu(null_select);
    glutAddMenuEntry("PRESSIONE '+' para AUMENTAR", 0);
    glutAddMenuEntry("PRESSIONE '-' para DIMINUIR", 0);

    glutCreateMenu(menu_select);
    glutAddMenuEntry(" ! Menu de Ações ! ", 0);
    glutAddSubMenu("Animação do Robo", glut_menu[8]);
    glutAddSubMenu("Rotação do Robo", glut_menu[7]);
    glutAddSubMenu("Rotação da Cabeça",glut_menu[6] );
    glutAddSubMenu("Rotação dos Braços", glut_menu[0]);
    glutAddSubMenu("Rotação das Pernas", glut_menu[3]);
    glutAddSubMenu("Para da ZOOM na Camera", glut_menu[9]);
    glutAddMenuEntry("Fechar", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    // Inicialização do GLUT e criação da janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 800);
    window = glutCreateWindow("Robo CG 2023 ");

    // Inicialização das configurações
    init();

    // Definição das funções de callback
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(inputZoomAndAnimate);
    glutSpecialFunc(inputCameraControl);
    glutMenu();
    
    // Loop principal do GLUT
    glutMainLoop();

    return 1;
}

// Inicialização das configurações iniciais do OpenGL
void init() {
    glClearColor(1.5, 1.5, 1.5, 0.0);
    glClearDepth(1.0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    // Configuração das angulações iniciais para caminhar
    caminhar_angulos[0][3] = angulo_virilhaE;
    caminhar_angulos[1][3] = angulo_virilhaD;
    movimento_base = calculaMovimentoBase(angulo_virilhaE, angulo_joelhoE, angulo_virilhaD, angulo_joelhoD);
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
      glTranslatef(0.0, 0.0, zoom);
      glRotatef(rotacaoy, 0.0, 1.0, 0.0);
      glRotatef(rotacaox, 1.0, 0.0, 0.0);

      quadril();
      pernas();
      torso();
      cabeca();
      bracos();
   glPopMatrix();

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
      glLoadIdentity();
      gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
         glLoadIdentity();

         glColor3f(0.0, 0.0, 0.0); // Cor do texto (preto)
         drawText("CLIQUE com bot�o DIREITO do mouse para ver o MENU", 10, glutGet(GLUT_WINDOW_HEIGHT) - 30);

      glPopMatrix();
      glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   glutSwapBuffers();
}

void inputZoomAndAnimate(unsigned char key, int x, int y) {
	if(key == 27){
		glutDestroyWindow(window); 
	}

   switch (key) {
      case '-':
         zoom -= 0.5;
         break;
      case '+':
         zoom += 0.5;
         break;
      case 'a':
        anima();
        break;
      case 's':
         shoulder1 = (shoulder1 + 5) % 360;
         break;
      case 'S':
         shoulder1 = (shoulder1 - 5) % 360;
         break;
      case 'h':
         head = (head - 5) %360;
         break;
      case 'H':
         head = (head + 5) %360;
         break;
      case 'e':
         elbow1 = (elbow1 - 5) % 360;
         break;
      case 'E':
         elbow1 = (elbow1 + 5) % 360;
         break;  
      case 'd':
         shoulder2 = (shoulder2 + 5) % 360;
         break;
      case 'D':
         shoulder2 = (shoulder2 - 5) % 360;
         break;
      case 'f':
         elbow2 = (elbow2 - 5) % 360;
         break;
      case 'F':
         elbow2 = (elbow2 + 5) % 360;

         break;
      case 'l':
         leg11 = (leg11 + 5) % 360;
         break;
      case 'L':
         leg11 = (leg11 - 5) % 360;
         break;
      case 'm':
         leg12 = (leg12 + 5) % 360;
         break;
      case 'M':
         leg12 = (leg12 - 5) % 360;
         break;
      case 'n':
         leg21 = (leg21 + 5) % 360;
         break;
      case 'N':
         leg21 = (leg21 - 5) % 360;
         break;
      case 'o':
         leg22 = (leg22 + 5) % 360;
         break;
      case 'O':
         leg22 = (leg22 - 5) % 360;
         break;
   }
   glutPostRedisplay();
}

void inputCameraControl( int tecla, int x, int y )  {
	if( tecla == GLUT_KEY_UP){
		rotacaox = (rotacaox + 5) % 360 ;
		glutPostRedisplay() ;	
	} 

   if( tecla == GLUT_KEY_DOWN){
		rotacaox = (rotacaox - 5) % 360 ;
		glutPostRedisplay() ;				
	}
	if( tecla == GLUT_KEY_LEFT){
		rotacaoy = (rotacaoy + 5) % 360 ;
		glutPostRedisplay() ;				
	}

	if( tecla == GLUT_KEY_RIGHT){
		rotacaoy = (rotacaoy - 5) % 360 ;
		glutPostRedisplay() ;				
	}
}


void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);

  glMatrixMode( GL_MODELVIEW );  
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -5.0);
}
