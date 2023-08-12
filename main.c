
#include "modelo.c"
#include <stdlib.h>
int window;

float caminhar_angulos[2][6];

double movimento_base = 0.0;
shoulder1 = 0;
elbow1 = 0;
shoulder2 = 0;
elbow2 = 0;
leg11=0;
leg12=0;
leg21=0;
leg22=0;
head=0;

float	angulo_virilhaE = 30,
		angulo_joelhoE  = 0,
		angulo_virilhaD = -30,
		angulo_joelhoD  = 0,
		zoom			= 1.0;

int rotacaox = 0,	rotacaoy = 0;

void menu_select(int mode){
 switch (mode) {
  case 4:
    exit(EXIT_SUCCESS);
  }
}
void null_select(int mode){}

void glutMenu(void){
   int glut_menu[10];
   glut_menu[1] = glutCreateMenu(null_select);
   glutAddMenuEntry("AT THE  SHOULDERS : s,S", 0);
   glutAddMenuEntry("AT THE ELBOW : e,E", 0);

   glut_menu[2] = glutCreateMenu(null_select);
   glutAddMenuEntry("AT THE  SHOULDERS : d,D", 0);
   glutAddMenuEntry("AT THE ELBOW : f,F", 0);

   glut_menu[4] = glutCreateMenu(null_select);
   glutAddMenuEntry("AT THE  HIP : l,L", 0);
   glutAddMenuEntry("AT THE KNEES : m,M", 0);

   glut_menu[5] = glutCreateMenu(null_select);
   glutAddMenuEntry("AT THE  HIP : n,N", 0);
   glutAddMenuEntry("AT THE KNEES : o,O", 0);

   glut_menu[6] = glutCreateMenu(null_select);
   glutAddMenuEntry("MOVE THE LEFT BUTTON OF THE MOUSE HORIZONTALLY", 0);

   glut_menu[3] = glutCreateMenu(NULL);
   glutAddSubMenu("LEG 1", glut_menu[4]);
   glutAddSubMenu("LEG 2", glut_menu[5]);

   glut_menu[0] = glutCreateMenu(null_select);
   glutAddSubMenu("HAND 1", glut_menu[1]);
   glutAddSubMenu("HAND 2", glut_menu[2]);

   glut_menu[7] = glutCreateMenu(null_select);
   glutAddMenuEntry("USE ARROW KEYS", 0);

   glutCreateMenu(menu_select);
   glutAddMenuEntry("WHAT CAN I DO??? ", 0);  
   glutAddSubMenu("ROBOT ROTATION", glut_menu[7]);
   glutAddSubMenu("HAND ROTATION", glut_menu[0]);
   glutAddSubMenu("LEG ROTATION", glut_menu[3]);
   glutAddSubMenu("TO MOVE THE CAMERA",glut_menu[6] );
   glutAddMenuEntry("Quit", 4);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(400, 400);
   window = glutCreateWindow("Boneco ");

   init();

   glutReshapeFunc(reshape);
   glutDisplayFunc(display);

   glutKeyboardFunc(inputZoomAndAnimate);
   glutSpecialFunc(inputCameraControl);
   glutMenu();
   glutMainLoop();

   return 1;
}

void init() {
   glClearColor(1.5, 1.5, 1.5, 0.0);
   glClearDepth(1.0);
   glDepthFunc(GL_LEQUAL);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   caminhar_angulos[0][3] = angulo_virilhaE;
   caminhar_angulos[1][3] = angulo_virilhaD ;
   movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix() ;

   glPushMatrix() ;
   glTranslatef(0.0,0.0, zoom);  // tran,rot = zooming
   glRotatef(rotacaoy,0.0,1.0,0.0);// rot,tran = moving
   glRotatef(rotacaox,1.0,0.0,0.0);// rot,tran = moving

   quadril();
   pernas();
   torso();
   cabeca();
   bracos();

   glPopMatrix();
   glPopMatrix();

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
