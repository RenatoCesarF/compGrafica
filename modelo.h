
// #include <GLUT/freeglut_std.h>
// #include <GLUT/gl.h>
#include <GLUT/glut.h>
#include <stdio.h>

#include <math.h>

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
#define HAND_HEIGHT LO_ARM_HEIGHT / 2.0
#define HAND_WIDTH LO_ARM_WIDTH
#define HAND LO_ARM_WIDTH / 2.0
#define HEAD_WIDTH HEAD_HEIGHT * 0.93
#define HEAD_HEIGHT TORSO_HEIGHT * 0.375
#define HEAD_JOINT_SIZE HEAD_HEIGHT / 6
#define BASE_WIDTH TORSO_WIDTH
#define BASE_HEIGHT TORSO_HEIGHT / 4.0
#define UP_LEG_HEIGHT LO_ARM_HEIGHT
#define UP_LEG_JOINT_SIZE UP_ARM_JOINT_SIZE
#define UP_LEG_WIDTH UP_LEG_JOINT_SIZE * 2.0
#define LO_LEG_HEIGHT UP_LEG_HEIGHT
#define LO_LEG_WIDTH UP_LEG_WIDTH
#define LO_LEG_JOINT_SIZE UP_LEG_JOINT_SIZE
#define LEG_HEIGHT                                                             \
  UP_LEG_HEIGHT + LO_LEG_HEIGHT + FOOT_HEIGHT +                                \
      2 * (FOOT_JOINT_SIZE + UP_LEG_JOINT_SIZE + LO_LEG_JOINT_SIZE)
#define QUADROS	 5
//-----

#ifndef PI
#define PI 3.1415
#endif

#define TORNOZELO				PESCOCO
#define ALTURA_PE				TORNOZELO * 2.0
#define LARGURA_PE				LARGURA_CANELA
#define PE						LARGURA_PE * 2.0
#define ALTURA_BRACO			ALTURA_TRONCO * 0.625
#define LARGURA_BRACO			LARGURA_TRONCO/4.0
#define OMBRO					PESCOCO * 2.0
#define ALTURA_ANTEBRACO        ALTURA_TRONCO * 0.5
#define LARGURA_ANTEBRACO       LARGURA_BRACO
#define COTOVELO				OMBRO * 0.75
#define ALTURA_MAO				ALTURA_ANTEBRACO / 2.0
#define LARGURA_MAO				LARGURA_ANTEBRACO
#define MAO						LARGURA_ANTEBRACO / 2.0
#define DEDO					0.1
#define LARGURA_TRONCO			ALTURA_TRONCO * 0.75
#define ALTURA_TRONCO			0.8
#define TRONCO					LARGURA_TRONCO / 3.0
#define LARGURA_CABECA          ALTURA_CABECA * 0.93
#define ALTURA_CABECA 			ALTURA_TRONCO * 0.375
#define PESCOCO					ALTURA_CABECA/6
#define LARGURA_QUADRIL			LARGURA_TRONCO
#define ALTURA_QUADRIL			ALTURA_TRONCO / 4.0
#define ALTURA_COXA				ALTURA_ANTEBRACO
#define VIRILHA					OMBRO
#define LARGURA_COXA			VIRILHA * 2.0
#define ALTURA_CANELA			ALTURA_COXA
#define LARGURA_CANELA          LARGURA_COXA
#define JOELHO					VIRILHA
#define ALTURA_PERNA			ALTURA_COXA + ALTURA_CANELA + ALTURA_PE + 2*(TORNOZELO+VIRILHA+JOELHO)

#define ESQUERDA 0
#define DIREITA  1
#define SOLIDO	 1
#define ARAME	 2	

extern double movimento_base ;
extern float caminhar_angulos[2][6];
extern float	angulo_virilhaE ,
				angulo_joelhoE  ,
				angulo_virilhaD ,
				angulo_joelhoD  ;

extern float zoom ;

extern int rotacao ;


double	calculaMovimentoBase(double angle_up, double angle_lo, double up, double lo) ;
void	anima(void);

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
void braco();
void antebraco();
void bracos();
void cabeca();
