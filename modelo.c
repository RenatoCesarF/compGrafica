
#include "modelo.h"

// Função para desenhar a parte do quadril do robô
void quadril() {
    glPushMatrix();
      // Escalando e transladando para posicionar o quadril
      glScalef(BASE_WIDTH, BASE_HEIGHT, TORSO);
      glTranslatef(0.0, 0.0, 0.0);
      
      // Desenha um cubo com fios para representar o quadril
      glColor3f(0.0, 1.0, 1.0); // Ciano
      glutWireCube(1.0);
      glColor3f(0.4, 0.2, 0.0); // Marrom escuro
      glutSolidCube(1.0);
    glPopMatrix();
}

// Função para desenhar a parte da coxa da perna
void coxa() {
   glPushMatrix();
      // Escalando e desenhando uma esfera para a articulação superior da perna
      glScalef(UP_LEG_JOINT_SIZE, UP_LEG_JOINT_SIZE, UP_LEG_JOINT_SIZE);
      glColor3f(0.0, 0.7, 0.5); // Verde claro
      glutWireSphere(1.0, 8, 8);
   glPopMatrix();

   // Transladando e desenhando a parte da coxa da perna
   glTranslatef(0.0, -UP_LEG_HEIGHT * 0.75, 0.0);
   glPushMatrix();
      glScalef(UP_LEG_WIDTH, UP_LEG_HEIGHT, UP_LEG_WIDTH);
      glColor3f(0.5, 0.7, 0.9); // Azul claro
      glutSolidCube(1.0);
      glColor3f(0, 0, 0); // Preto
      glutWireCube(1.0);
    glPopMatrix();
}

// Função para desenhar a parte do pé da perna
void pe() {
   glPushMatrix();
      // Desenhando uma esfera para a articulação do pé
      glScalef(FOOT_JOINT_SIZE, FOOT_JOINT_SIZE, FOOT_JOINT_SIZE);
      glColor3f(0.0, 0.7, 0.5); // Verde claro
      glutWireSphere(1.0, 8, 8);
   glPopMatrix();

   // Transladando e desenhando a parte do pé da perna
   glPushMatrix();
      glTranslatef(0.0, -FOOT_HEIGHT * 0.75, FOOT_WIDTH * 0.5);
      glPushMatrix();
         glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT);
         glColor3f(1.0, 0.5, 0.0); // Laranja
         glutSolidCube(1.0);
         glColor3f(0.5, 0.0, 1.0); // Roxo
         glutWireCube(1.0);
      glPopMatrix();
   glPopMatrix();
}


void perna(int side) {
   glPushMatrix();
      // Realiza rotação inicial com base no lado da perna
      if(side == DIREITA)
         glRotatef ((GLfloat) leg11, 0.0, 0.0, 1.0);
      else
         glRotatef ((GLfloat) leg21, 0.0, 0.0, 1.0);	
      
      // Aplica rotação nos ângulos de caminhar da perna
      glRotatef(caminhar_angulos[side][3], 1.0, 0.0, 0.0);

      coxa();  // Chama a função "coxa" para renderizar a coxa da perna
      glTranslatef(0.0, -UP_LEG_HEIGHT * 0.75, 0.0);
      glRotatef(caminhar_angulos[side][4], 1.0, 0.0, 0.0);

      // Realiza rotação adicional baseada no lado da perna
      if(side == DIREITA)
         glRotatef ((GLfloat) leg12, 0.0, 0.0, 1.0);
      else
         glRotatef ((GLfloat) leg22, 0.0, 0.0, 1.0);
      
      panturrilha();  // Chama a função "panturrilha" para renderizar a panturrilha da perna
      glTranslatef(0.0, -LO_LEG_HEIGHT * 0.625, 0.0);
      glRotatef(caminhar_angulos[side][5], 1.0, 0.0, 0.0);

      pe();  // Chama a função "pe" para renderizar o pé da perna
   glPopMatrix();
}

void panturrilha() {
   glPushMatrix();
      // Desenha a esfera do joelho
      glScalef(LO_LEG_JOINT_SIZE, LO_LEG_JOINT_SIZE, LO_LEG_JOINT_SIZE);
      glColor3f(0.0, 0.7, 0.5);   // Define a cor da esfera do joelho
      glutWireSphere(1.0, 8, 8);  // Renderiza a esfera do joelho em arame
   glPopMatrix();

   glTranslatef(0.0, -LO_LEG_HEIGHT * 0.75, 0.0);  // Translada para posicionar a panturrilha inferior

   glPushMatrix();
      glScalef(LO_LEG_WIDTH, LO_LEG_HEIGHT, LO_LEG_WIDTH);  // Escala a panturrilha inferior
      glColor3f(1.0, 0.0, 1.0);  // Define a cor do cubo de arame da panturrilha inferior
      glutWireCube(1.0);  // Renderiza o cubo de arame da panturrilha inferior
      glColor3f(0.6, 0.8, 1.0);
      glutSolidCube(1);
   glPopMatrix();
}


void pernas() {
   glPushMatrix();
      // Desce a altura para a posição das pernas em relação ao corpo
      glTranslatef(0.0, -(BASE_HEIGHT), 0.0);
      
      // Renderiza a perna direita
      glPushMatrix();
         glTranslatef(TORSO_WIDTH * 0.33, 0.0, 0.0);
         perna(DIREITA);  // Chama a função "perna" para renderizar a perna direita
      glPopMatrix();

      // Renderiza a perna esquerda
      glPushMatrix();
         glTranslatef(-TORSO_WIDTH * 0.33, 0.0, 0.0);
         perna(ESQUERDA);  // Chama a função "perna" para renderizar a perna esquerda
      glPopMatrix();

   glPopMatrix();
}

void torso() {
   glPushMatrix();
      // Translada para posicionar o torso verticalmente e centralizado
      glTranslatef(0.0, BASE_HEIGHT / 2.0 + TORSO_HEIGHT / 2.0, 0.0);
      // Escala o torso para definir suas dimensões
      glScalef(TORSO_WIDTH, TORSO_HEIGHT, TORSO); 
      // Renderiza o cubo de arame do torso (cor preta)
      glColor3f(0.0, 0.0, 0.0);
      glutWireCube(1.0);
      // Renderiza o cubo sólido do torso (cor marrom claro)
      glColor3f(0.6, 0.3, 0.1);
      glutSolidCube(1.0);
   glPopMatrix();
}


void braco_completo(int side){
   glPushMatrix();
      // Transformações iniciais para posicionar o braço
      glPushMatrix();
         // Translada para a posição inicial do ombro
         glTranslatef(0.4, UP_ARM_HEIGHT * 1.55 + LO_ARM_JOINT_SIZE * 3, 0.0);
         // Translada para o centro do braço
         glTranslatef(0.0, -UP_ARM_JOINT_SIZE * 2, 0.0);
         
         // Realiza rotação inicial do ombro com base no lado
         if (side == DIREITA)
            glRotatef ((GLfloat) shoulder1, 0.0, 0.0, 1.0);
         else
            glRotatef ((GLfloat) shoulder2, 0.0, 0.0, 1.0);
            
            // Desenha a esfera do ombro
            glPushMatrix();
               glColor3f(0.0, 0.7, 0.5);  // Cor da esfera do ombro
               glScalef(UP_ARM_JOINT_SIZE, UP_ARM_JOINT_SIZE, UP_ARM_JOINT_SIZE);
               glutWireSphere(1.0, 8, 8);
            glPopMatrix();

         // Translada para a posição do cotovelo e redimensiona o braço superior
         glTranslatef(0.0, -UP_ARM_JOINT_SIZE - UP_ARM_HEIGHT / 2, 0.0);
         glScalef(UP_ARM_WIDTH, UP_ARM_HEIGHT, UP_ARM_WIDTH);
         glColor3f(0.4392, 0.2392, 0.4353); // Cor do cubo sólido do braço superior
         glutSolidCube(1.0); 
         
         glColor3f(0, 0.8, 0.6); // Cor do cubo de arame do braço superior
         glutWireCube(1.0);

         // Ante Braço
         glTranslatef(-4.8, -1.6, 0.0);
         glScalef(6, 2, 6);
         glTranslatef((TORSO_WIDTH * 0.66) * 2, LO_ARM_HEIGHT * 2, 0.0);

         glPushMatrix();
            // Translada para a posição inicial do cotovelo
            glTranslatef(0.0, -LO_ARM_JOINT_SIZE * 4, 0.0);
            // Realiza rotação do cotovelo com base no lado
            if(side == DIREITA)
               glRotatef ((GLfloat) elbow1, 1.0, 0.0, 0.0);
            else 
               glRotatef ((GLfloat) elbow2, 1.0, 0.0, 0.0);

               // Desenha a esfera do cotovelo
               glPushMatrix();
                  glColor3f(0.0, 0.7, 0.5);  // Cor da esfera do cotovelo
                  glScalef(LO_ARM_JOINT_SIZE, LO_ARM_JOINT_SIZE, LO_ARM_JOINT_SIZE);
                  glutWireSphere(1.0, 8, 8);
               glPopMatrix();

            // Translada para a posição do antebraço e redimensiona
            glTranslatef(0.0, -LO_ARM_JOINT_SIZE - LO_ARM_HEIGHT / 2, 0.0);
            glScalef(LO_ARM_WIDTH, LO_ARM_HEIGHT, LO_ARM_WIDTH);
            glColor3f(0, 0.8, 0.6); // Cor do cubo de arame do antebraço
            glutWireCube(1.0);

            glColor3f(0.4392, 0.2392, 0.4353); // Cor do cubo sólido do antebraço
            glutSolidCube(1.0);

         glPopMatrix();
      glPopMatrix();
   glPopMatrix();
}
void bracos() {
   braco_completo(DIREITA);
   glTranslatef(-TORSO_WIDTH -0.20, 0.0, 0.0);
   braco_completo(ESQUERDA);
}
void cabeca() {
   glPushMatrix();
      glColor3f(0.0, 0.7, 0.5);  // Define a cor da esfera da articulação da cabeça
      glRotatef ((GLfloat) head, 0.0, 1.0, 0.0);  // Realiza rotação da cabeça
      glTranslatef(0.0, BASE_HEIGHT / 2.0 + TORSO_HEIGHT + HEAD_JOINT_SIZE, 0.0);  // Translada para a posição da articulação da cabeça

      glScalef(HEAD_JOINT_SIZE, HEAD_JOINT_SIZE, HEAD_JOINT_SIZE);  // Escala a esfera da articulação da cabeça
      glutWireSphere(1.0, 8, 8);  // Renderiza a esfera da articulação da cabeça em arame
   glPopMatrix();

   glPushMatrix();
      glRotatef ((GLfloat) head, 0.0, 1.0, 0.0);  // Realiza rotação da cabeça novamente
      glTranslatef(0.0, TORSO_HEIGHT + HEAD_JOINT_SIZE + HEAD_HEIGHT, 0.0);  // Translada para a posição da cabeça

      glScalef(HEAD_WIDTH, HEAD_HEIGHT, HEAD_WIDTH);  // Escala a cabeça
      glColor3f(0,0,0);  // Define a cor do cubo de arame da cabeça
      glutWireCube(1.0);  // Renderiza o cubo de arame da cabeça
      glColor3f(0.8, 0.0, 0.0);  // Define a cor do cubo sólido da cabeça
      glutSolidCube(1.0);  // Renderiza o cubo sólido da cabeça

   glPopMatrix();
}

double calculaMovimentoBase(double langle_up, double langle_lo, double rangle_up, double rangle_lo){
   double result1, result2, first_result, second_result, radians_up, radians_lo;

   // Calcula os ângulos em radianos
   radians_up = (PI*langle_up)/180.0;
   radians_lo = (PI*langle_lo-langle_up)/180.0;

   // Calcula os resultados intermediários
   result1 = (LO_ARM_HEIGHT + 2*KNEE) * cos(radians_up);
   result2 = (LO_ARM_HEIGHT + 2*(KNEE+FOOT_JOINT_SIZE)+FOOT_HEIGHT) * cos(radians_lo);
   first_result = FOOT_HEIGHT - (result1 + result2);

   // Calcula os ângulos em radianos
   radians_up = (PI*rangle_up)/180.0;
   radians_lo = (PI*rangle_lo-rangle_up)/180.0;

   // Calcula os resultados intermediários
   result1 = (LO_ARM_HEIGHT + 2*KNEE) * cos(radians_up);
   result2 = (LO_ARM_HEIGHT + 2*(KNEE+FOOT_JOINT_SIZE)+FOOT_HEIGHT) * cos(radians_lo);
   second_result = FOOT_HEIGHT - (result1 + result2);

   // Retorna o menor entre os dois resultados calculados
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
