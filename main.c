
#include "modelo.c"
int window;

float caminhar_angulos[2][6];

double movimento_base = 0.0;

float	angulo_virilhaE = 30 ,
		angulo_joelhoE  = 0,
		angulo_virilhaD = -30,
		angulo_joelhoD  = 0,
		zoom			= 1.0;

int rotacaox = 0,	rotacaoy = 0;

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



  // glPushMatrix();
  // glTranslatef(0.0,movimento_base,0.0);
  // quadril();
  // glTranslatef(0.0,-(ALTURA_QUADRIL),0.0);
  // glPushMatrix();

  // glTranslatef(LARGURA_TRONCO * 0.33,0.0,0.0);
  // perna(ESQUERDA);
  // glPopMatrix();

  // glTranslatef(-LARGURA_TRONCO * 0.33,0.0,0.0);
  // perna(DIREITA);
  // glPopMatrix();
  quadril();
  pernas();
  torso();
  cabeca();
  bracos();

	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void inputZoomAndAnimate(unsigned char tecla, int x, int y) {
	if (tecla == '-'){
		zoom -= 0.5;
		glutPostRedisplay() ;
		return;
	}	
	if (tecla == '+'){
		zoom += 0.5;
		glutPostRedisplay() ;
		return;
	}	
	if(tecla == 27){
		glutDestroyWindow(window); 
	}
	if(tecla =='a'){
		anima();

		glutPostRedisplay();
	}
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
