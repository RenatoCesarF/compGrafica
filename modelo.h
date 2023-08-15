#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GLUT/freeglut_std.h>
	#include <GLUT/gl.h>
#endif

#define QUADROS	 3
#define PI 3.1415

#define ESQUERDA 0
#define DIREITA  1


// A altura do torso define as dimensões de todos os outros elementos
#define TORSO_HEIGHT 0.8
#define TORSO_WIDTH TORSO_HEIGHT * 0.75
#define TORSO TORSO_WIDTH / 3.0

#define FOOT_JOINT_SIZE HEAD_JOINT_SIZE
#define FOOT_HEIGHT FOOT_JOINT_SIZE * 2.0
#define FOOT_WIDTH LO_LEG_WIDTH
#define FOOT FOOT_WIDTH * 2.0

#define UP_ARM_HEIGHT TORSO_HEIGHT * 0.625
#define UP_ARM_WIDTH TORSO_WIDTH / 4.0
#define UP_ARM_JOINT_SIZE HEAD_JOINT_SIZE * 2.0

#define LO_ARM_HEIGHT TORSO_HEIGHT * 0.5
#define LO_ARM_WIDTH UP_ARM_WIDTH
#define LO_ARM_JOINT_SIZE UP_ARM_JOINT_SIZE * 0.75

#define HEAD_WIDTH HEAD_HEIGHT * 0.93
#define HEAD_HEIGHT TORSO_HEIGHT * 0.375
#define HEAD_JOINT_SIZE HEAD_HEIGHT / 6

#define BASE_WIDTH TORSO_WIDTH * 0.8
#define BASE_HEIGHT TORSO_HEIGHT / 4.0
#define UP_LEG_HEIGHT LO_ARM_HEIGHT
#define UP_LEG_JOINT_SIZE UP_ARM_JOINT_SIZE
#define UP_LEG_WIDTH UP_LEG_JOINT_SIZE * 2.0
#define LO_LEG_HEIGHT UP_LEG_HEIGHT
#define LO_LEG_WIDTH UP_LEG_WIDTH
#define KNEE					(TORSO_HEIGHT * 0.375)/6 * 2.0
#define LO_LEG_JOINT_SIZE UP_LEG_JOINT_SIZE

//-----



extern double movimento_base ;
extern float caminhar_angulos[2][6];
extern float	angulo_virilhaE ,
				angulo_joelhoE  ,
				angulo_virilhaD ,
				angulo_joelhoD  ;

extern float zoom ;

extern int rotacao ;

extern int shoulder1;
extern int elbow1;
extern int shoulder2;
extern int elbow2;
extern int leg11;
extern int leg12;
extern int leg21;
extern int leg22;
extern int head;

double	calculaMovimentoBase(double angle_up, double angle_lo, double up, double lo) ;
void	anima(void);

void drawText(const char *text, float x, float y);
void inputZoomAndAnimate(unsigned char tecla, int x, int y);
void inputCameraControl( int tecla, int x, int y );
void init();
void display();
void reshape(int, int);

void quadril();
void perna(int side);
void panturrilha();
void pe();
void coxa();
void pernas();
void torso();
void bracos();
void cabeca();
