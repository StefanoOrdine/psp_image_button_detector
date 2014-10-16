#include <pspdisplay.h>
#include <pspctrl.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <png.h>
#include <stdio.h>
#include "graphics.h"

//Definizione della funzione Printf
#define printf pspDebugScreenPrintf 

//Informazioni sul progetto
PSP_MODULE_INFO("PSP_BUTTON_IMAGE_VERSION", 0, 1, 1); 

//Callbacks necessarie al funzionamento del progetto

/* Exit callback */
int exit_callback(int arg1, int arg2, void *common) {
          sceKernelExitGame();
          return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp) {
          int cbid;

          cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
          sceKernelRegisterExitCallback(cbid);

          sceKernelSleepThreadCB();

          return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void) {
          int thid = 0;

          thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
          if(thid >= 0) {
                    sceKernelStartThread(thid, 0, 0);
          }

          return thid;
} 

//Funzione primaria del progetto
int main()
{

//settaggio funzioni grafiche
pspDebugScreenInit();
initGraphics();

//Settaggio Callbacks
SetupCallbacks();

//Dichiarazione Variabili
int controllo=0;
Image* V[12];
SceCtrlData pad;

//Semplice stampa a video
printf("Caricamento...");

//Assegnazione immagini al vettore V
V[0] = loadImage("./Immagini/psp.png");
V[1] = loadImage("./Immagini/l.png");
V[2] = loadImage("./Immagini/left.png");
V[3] = loadImage("./Immagini/up.png");
V[4] = loadImage("./Immagini/down.png");
V[5] = loadImage("./Immagini/right.png");
V[6] = loadImage("./Immagini/select.png");
V[7] = loadImage("./Immagini/start.png");
V[8] = loadImage("./Immagini/square.png");
V[9] = loadImage("./Immagini/triangle.png");
V[10] = loadImage("./Immagini/cross.png");
V[11] = loadImage("./Immagini/circle.png");
V[12] = loadImage("./Immagini/r.png");

//Stampa Sfondo
blitAlphaImageToScreen(0, 0, 480, 272, V[0], 0, 0);
sceDisplayWaitVblankStart();
flipScreen();

while(1)
	{
	//rilevamento pressione tasti
	sceCtrlReadBufferPositive(&pad,1);
	//controllo pressione trigger sinistro
	if(pad.Buttons & PSP_CTRL_LTRIGGER)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[1], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione freccia sinistra
	if(pad.Buttons & PSP_CTRL_LEFT)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[2], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione freccia su
	if(pad.Buttons & PSP_CTRL_UP)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[3], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione freccia giù
	if(pad.Buttons & PSP_CTRL_DOWN)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[4], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione freccia destra
	if(pad.Buttons & PSP_CTRL_RIGHT)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[5], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione select
	if(pad.Buttons & PSP_CTRL_SELECT)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[6], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione start
	if(pad.Buttons & PSP_CTRL_START)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[7], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione quadrato
	if(pad.Buttons & PSP_CTRL_SQUARE)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[8], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione triangolo
	if(pad.Buttons & PSP_CTRL_TRIANGLE)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[9], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione x
	if(pad.Buttons & PSP_CTRL_CROSS)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[10], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione cerchio
	if(pad.Buttons & PSP_CTRL_CIRCLE)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[11], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione trigger destro
	if(pad.Buttons & PSP_CTRL_RTRIGGER)
		{
		controllo=1;
		blitAlphaImageToScreen(0, 0, 480, 272, V[12], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	//controllo pressione tasti
	if(controllo==0)
		{
		//stampa sfondo
		blitAlphaImageToScreen(0, 0, 480, 272, V[0], 0, 0);
		sceDisplayWaitVblankStart();
		flipScreen();
		}
	controllo=0;
	}
//ferma la funzione
sceKernelSleepThread();
//valore di ritorno funzione int main
return 0;
}

