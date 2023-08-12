
#include "modelo.h"

void quadril() {
  glPushMatrix();

  glScalef(BASE_WIDTH, BASE_HEIGHT, TORSO);
  glColor3f(0.0, 1.0, 1.0);
  glTranslatef(0.0, 0.0, 0.0);
  glutWireCube(1.0);

  glPopMatrix();
}

void coxa() {
  glPushMatrix();

  glScalef(UP_LEG_JOINT_SIZE, UP_LEG_JOINT_SIZE, UP_LEG_JOINT_SIZE);
  glColor3f(0.0, 1.0, 0.0);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glTranslatef(0.0, -UP_LEG_HEIGHT * 0.75, 0.0);

  glPushMatrix();

  glScalef(UP_LEG_WIDTH, UP_LEG_HEIGHT, UP_LEG_WIDTH);
  glColor3f(0.5, 0.5, 0.5);
  glutWireCube(1.0);

  glPopMatrix();
}

void panturrilha() {
  glPushMatrix();

  // desenha joelho
  glScalef(LO_LEG_JOINT_SIZE, LO_LEG_JOINT_SIZE, LO_LEG_JOINT_SIZE);
  glColor3f(0.0, 1.0, 0.0);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glTranslatef(0.0, -LO_LEG_HEIGHT * 0.75, 0.0);

  glPushMatrix();

  glScalef(LO_LEG_WIDTH, LO_LEG_HEIGHT, LO_LEG_WIDTH);
  glColor3f(1.0, 0.0, 1.0);
  glutWireCube(1.0);

  glPopMatrix();
}

void pe() {
  glPushMatrix();

  // desenha FOOT_JOINT_SIZE
  glScalef(FOOT_JOINT_SIZE, FOOT_JOINT_SIZE, FOOT_JOINT_SIZE);
  glColor3f(0.0, 1.0, 0.0);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glPushMatrix();

  glTranslatef(0.0, -FOOT_HEIGHT * 0.75, FOOT_WIDTH * 0.5);

  glPushMatrix();

  glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT);
  glColor3f(0.5, 0.0, 1.0);

  glutWireCube(1.0);

  glPopMatrix();
  glPopMatrix();
};

void perna(int side) {
   glPushMatrix();
   glRotatef(caminhar_angulos[side][3],1.0,0.0,0.0);

  coxa();
  glTranslatef(0.0, -UP_LEG_HEIGHT * 0.75, 0.0);
  glRotatef(caminhar_angulos[side][4],1.0,0.0,0.0);

  panturrilha();
  glTranslatef(0.0, -LO_LEG_HEIGHT * 0.625, 0.0);
  glRotatef(caminhar_angulos[side][5],1.0,0.0,0.0);

  pe();

  glPopMatrix();
}

void pernas() {
  glPushMatrix();

  // desce a altura para as pernas
  glTranslatef(0.0, -(BASE_HEIGHT), 0.0);

  // perna direita
  glPushMatrix();
  glTranslatef(TORSO_WIDTH * 0.33, 0.0, 0.0);
  perna(DIREITA);
  glPopMatrix();

  // perna esquerda
  glPushMatrix();
  glTranslatef(-TORSO_WIDTH * 0.33, 0.0, 0.0);
  perna(ESQUERDA);
  glPopMatrix();

  glPopMatrix();
}

void torso() {
  glPushMatrix();

  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(0.0, BASE_HEIGHT / 2.0 + TORSO_HEIGHT / 2.0, 0.0);
  glScalef(TORSO_WIDTH, TORSO_HEIGHT, TORSO);

  glutWireCube(1.0);

  glPopMatrix();
}

void antebraco() {
  glPushMatrix();

  glTranslatef(0.0, -LO_ARM_JOINT_SIZE * 4, 0.0);

  glPushMatrix();

  glColor3f(0.0, 1.0, 0.0);
  glScalef(LO_ARM_JOINT_SIZE, LO_ARM_JOINT_SIZE, LO_ARM_JOINT_SIZE);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glColor3f(0.5, 0.1, 0.3);
  glTranslatef(0.0, -LO_ARM_JOINT_SIZE - LO_ARM_HEIGHT / 2, 0.0);

  glScalef(LO_ARM_WIDTH, LO_ARM_HEIGHT, LO_ARM_WIDTH);
  glutWireCube(1.0);

  glPopMatrix();
}

void braco() {
  glPushMatrix();

  glTranslatef(0.0, -UP_ARM_JOINT_SIZE * 2, 0.0);

  glPushMatrix();

  glColor3f(0.0, 1.0, 0.0);
  glScalef(UP_ARM_JOINT_SIZE, UP_ARM_JOINT_SIZE, UP_ARM_JOINT_SIZE);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glColor3f(0.5, 0.1, 0.3);
  glTranslatef(0.0, -UP_ARM_JOINT_SIZE - UP_ARM_HEIGHT / 2, 0.0);

  glScalef(UP_ARM_WIDTH, UP_ARM_HEIGHT, UP_ARM_WIDTH);
  glutWireCube(1.0);

  glPopMatrix();
}

void bracos() {
  glPushMatrix();

  glTranslatef(TORSO_WIDTH * 0.66, LO_ARM_HEIGHT, 0.0);
  antebraco();

  glTranslatef(0.0, UP_ARM_HEIGHT * 0.875 + LO_ARM_JOINT_SIZE * 2, 0.0);
  braco();

  glPopMatrix();

  glPushMatrix();

  glTranslatef(TORSO_WIDTH * (-0.66), LO_ARM_HEIGHT, 0.0);
  antebraco();

  glTranslatef(0.0, UP_ARM_HEIGHT * 0.875 + LO_ARM_JOINT_SIZE * 2, 0.0);
  braco();

  glPopMatrix();
}

void cabeca() {
  glPushMatrix();

  glColor3f(0.0, 1.0, 0.0);
  glTranslatef(0.0, BASE_HEIGHT / 2.0 + TORSO_HEIGHT + HEAD_JOINT_SIZE, 0.0);

  glScalef(HEAD_JOINT_SIZE, HEAD_JOINT_SIZE, HEAD_JOINT_SIZE);
  glutWireSphere(1.0, 8, 8);

  glPopMatrix();

  glPushMatrix();

  glColor3f(0.1, 0.7, 0.2);
  glTranslatef(0.0, TORSO_HEIGHT + HEAD_JOINT_SIZE + HEAD_HEIGHT, 0.0);
  glScalef(HEAD_WIDTH, HEAD_HEIGHT, HEAD_WIDTH);
  glutWireCube(1.0);

  glPopMatrix();
}

double calculaMovimentoBase(double langle_up, double langle_lo, double rangle_up, double rangle_lo){
   double result1, result2, first_result, second_result, radians_up, radians_lo;

   radians_up = (PI*langle_up)/180.0;
   radians_lo = (PI*langle_lo-langle_up)/180.0;
   result1 = (ALTURA_COXA + 2*VIRILHA) * cos(radians_up);
   result2 = (ALTURA_CANELA + 2*(JOELHO+FOOT_JOINT_SIZE)+FOOT_HEIGHT)
             * cos(radians_lo);
   first_result = FOOT_HEIGHT- (result1 + result2);

   radians_up = (PI*rangle_up)/180.0;
   radians_lo = (PI*rangle_lo-rangle_up)/180.0;
   result1 = (ALTURA_COXA + 2*VIRILHA) * cos(radians_up);
   result2 = (ALTURA_CANELA + 2*(JOELHO+FOOT_JOINT_SIZE)+FOOT_HEIGHT)
             * cos(radians_lo);
   second_result = FOOT_HEIGHT - (result1 + result2);

   if (first_result <= second_result)
      return (- first_result);
   else
      return (- second_result);
}

void anima(void){
   static quadros = QUADROS,
          zoom_fl = 0,
          flag = 1;

   float difVirilhaE ,
      	difVirilhaD ,
      	somaVirilhaE ,
      	somaVirilhaD ,
      	difJoelhoE ,
      	difJoelhoD ,
      	somaJoelhoE ,
      	somaJoelhoD;

   switch (flag)
   {
      case 1 :
         difVirilhaE = 15;
         difVirilhaD = 5;
         difJoelhoE = 15;
         difJoelhoD = 5;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

       	caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  -= somaVirilhaE;
         angulo_joelhoE -= somaJoelhoE;
         angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 2;
            quadros = QUADROS;
         }
         break;
      case 2 :
         difVirilhaE = 20;
         difVirilhaD = -65;
         difJoelhoE = -15;
         difJoelhoD = 85;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  -= somaVirilhaE;
         angulo_joelhoE -= somaJoelhoE;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
         movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 3;
            quadros = QUADROS;
         }
         break;
      case 3 :
         difVirilhaE = 5;
         difVirilhaD = -25;
         difJoelhoE = 10;
         difJoelhoD = -40;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  -= somaVirilhaE;
         angulo_joelhoE -= somaJoelhoE;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 4;
            quadros = QUADROS;
         }
         break;
      case 4 :
         difVirilhaE = 20;
         difVirilhaD = 25;
         difJoelhoE = -10;
         difJoelhoD = -50;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  -= somaVirilhaE;
         angulo_joelhoE -= somaJoelhoE;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 5;
            quadros = QUADROS;
         }
         break;
		case 5 :
         difVirilhaE = 5;
         difVirilhaD = 15;
         difJoelhoE = 5;
         difJoelhoD = 15;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

       	caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  += somaVirilhaD;
         angulo_joelhoE += somaJoelhoD;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 6;
            quadros = QUADROS;
         }
         break;
      case 6 :
         difVirilhaE = -65;
         difVirilhaD = 20;
         difJoelhoE = 85;
         difJoelhoD = -15;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  += somaVirilhaD;
         angulo_joelhoE += somaJoelhoD;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 7;
            quadros = QUADROS;
         }
         break;
      case 7 :
         difVirilhaE = -25;
         difVirilhaD = 5;
         difJoelhoE = -40;
         difJoelhoD = 10;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  += somaVirilhaD;
         angulo_joelhoE += somaJoelhoD;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 8;
            quadros = QUADROS;
         }
         break;
      case 8 :
         difVirilhaE = 25;
         difVirilhaD = 20;
         difJoelhoE = -50;
         difJoelhoD = -10;

         somaVirilhaE = difVirilhaE / QUADROS;
       	somaVirilhaD = difVirilhaD / QUADROS;
         somaJoelhoE = difJoelhoE / QUADROS;
       	somaJoelhoD = difJoelhoD / QUADROS;

         caminhar_angulos[0][3] += somaVirilhaD;
   		caminhar_angulos[1][3] += somaVirilhaE;
       	caminhar_angulos[0][4] += somaJoelhoD;
   		caminhar_angulos[1][4] += somaJoelhoE;

         angulo_virilhaE  += somaVirilhaD;
         angulo_joelhoE += somaJoelhoD;
   		angulo_virilhaD -= somaVirilhaD;
         angulo_joelhoD -= somaJoelhoD;
   		movimento_base = calculaMovimentoBase(angulo_virilhaE,angulo_joelhoE,angulo_virilhaD,angulo_joelhoD );
         quadros--;
         if (quadros == 0)
         {
            flag = 1;
            quadros = QUADROS;
         }
         break;
      default :
         break;
   }


   glutPostRedisplay();
}
