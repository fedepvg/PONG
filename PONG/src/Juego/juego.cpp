#include "juego.h"

#include "raylib.h"
#include "Pantallas/pantallaJuego.h"
#include"Pantallas/pantallaMenu.h"
#include"Pantallas/pantallaGameOver.h"
#include "Pantallas/pantallaCreditos.h"

namespace Juego {

	static void inicializarJuego();
	static void inicializarPantallas();
	static void actualizar();
	static void dibujar();
	static void desInicializarPantallas();
	static void desinicializarJuego();

	using namespace PantallaJuego;
	estados estado = menu;
	int anchoPantalla = 900;
	int altoPantalla = 600;
	bool enJuego = true;

	void inicializarJuego() {
		InitWindow(anchoPantalla, altoPantalla, "PONG");
		InitAudioDevice();
	}

	void inicializarPantallas(){
		switch (estado) {
		case menu:
			Menu::inicializarMenu();
			break;
		case juego:
			inicializarPantJuego();
			break;
		default:break;
		}
	}
	
	void actualizar() {
		switch (estado) {
		case menu:
			Menu::actualizarMenu();
			break;
		case juego:
			actualizarJuego();
			break;
		case gameOver:
			GameOver::actualizarGO();
			break;
		case creditos:
			Creditos::actualizarCreditos();
			break;
		default:break;
		}
	}
	
	void dibujar() {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		switch (estado) {
		case menu:
			Menu::dibujarMenu();
			break;
		case juego:
			dibujarJuego();
			break;
		case gameOver:
			GameOver::dibujarGO();
			break;
		case creditos:
			Creditos::dibujarCreditos();
			break;
		default:break;
		}
		EndDrawing();
	}

	void desInicializarPantallas() {
		switch (estado) {
		case menu:
			Menu::desinicializarMenu();
			break;
		case juego:
			desinicializarPantJuego();
			break;
		default:break;
		}
	}

	void desinicializarJuego() {
		CloseAudioDevice();
		CloseWindow();
	}

	void ejecutar() {
		
		inicializarJuego();

		while (enJuego){
			inicializarPantallas();
			actualizar();
			dibujar();
			desInicializarPantallas();
		}

		desinicializarJuego();
	}
}