#include <stdlib.h>
#include <stdio.h>
#include <maclib.h>
/** le dessin: on aurrait pu mettre ces fonctions dans un fichier séparé  **/

#define scale 20
#define origin_h 0
#define origin_v 0


static void efface_ecran (void) {
	Rect r;
	SetRect(&r, 0, 0, 1000, 1000);
	EraseRect(&r);
}

static void dessine_cellule (Pattern c, int h, int v) {
	Rect r;
	PenPat (c);
	SetRect(&r, h*scale +origin_h, v*scale +origin_v,
			h*scale + scale +origin_h, v*scale + scale + origin_v);
	PaintRect(&r);
	PenPat (white);
	FrameRect(&r);
	PenPat (black);
}

static void selectionne (int* h, int* v) {
	Point p;
	GetClick (&p);
	*v = p.v / scale;
	*h = p.h / scale;
	return;
}


/** le programme proprement on dit  **/

#define TAILLE_MAX 7
#define CELL_MAX 13 
#define STOP_H 14
#define STOP_V 14

static int taille;
static int jeu [TAILLE_MAX+1];
static int joueur = 1;   /* 1 ou 2 */


static void test () {
	int n, v;
	while (1) {
		selectionne (&v, &n);
		dessine_cellule (gray, v,n);
	}
}


/* tirer_au_hasard (l, r) retourne r ou un entier n tel que r <= n < l  */
static int tirer_au_hasard (int l, int r) {
	if (r > l) return l + (abs (Random()) % (r-l));
	else return r;
}

static int ligne_correcte(ligne, valeur)
{
	return
		(ligne >= 0) && (ligne < taille) && 
		(valeur >= 0) && (valeur < jeu[ligne]);
}

static void efface_ligne(ligne, valeur)
{
	Pattern* c; int i;
	if (joueur == 1) c = &ltGray;
	else c = &dkGray;
	for (i = valeur; i < jeu[ligne]; i = i + 1)
		dessine_cellule(*c, i, ligne);
}

static void jouer_le_coup(ligne, valeur)
{
	printf("Joueur %d : case %d sur la ligne %d\n", joueur, 1+valeur, ligne);
	efface_ligne(ligne, valeur);
	jeu[ligne] = valeur;
	joueur = joueur % 2 + 1;
}

static void jouer_le_clique(int ligne, int valeur)
{
	while (!ligne_correcte(ligne, valeur)) {
		if  (valeur == STOP_H && ligne == STOP_V) exit (1);
		printf("coup inadmissible (joueur %d rejoue)\n", joueur);
		selectionne(&valeur, &ligne);
	}
	jouer_le_coup(ligne, valeur);
}


static int debut_du_jeu (void) {
	int i = 0; 
	while (i < taille && jeu[i] == 0) i = i+1;
	return i;;
}



static void jouer_au_hasard()
{
	int ligne, valeur;
	ligne = tirer_au_hasard (debut_du_jeu(), taille);
	while (jeu[ligne] == 0) ligne = ligne-1;
	valeur = tirer_au_hasard (0,jeu[ligne]);
	jouer_le_coup(ligne, valeur);
}

static void jouer_avec_intelligence (void)
{
	/*
	 *   calculer la difference en base deux entre toutes les lignes;
	 *     calculer le filtre (plus gros coefficient de la difference);
	 *       calculer le nombre de lignes filtrees;
	 *         tirer au hasard une ligne filtree;
	 *           calculer la valeur a jouer dans cette ligne;
	 *             */
}

static void jeu_par_defaut (void) 
{
	taille = 5;
	jeu[0]=1;
	jeu[1]=2;
	jeu[2]=3;
	jeu[3]=5;
	jeu[4]=7;
}

static void nouveau_jeu (void) {
	int n;
	taille = tirer_au_hasard (3,TAILLE_MAX);
	for (n = 0; n < taille; n = n+1)
		jeu[n] = tirer_au_hasard (n == 0 ? 0 : jeu[n-1], CELL_MAX);
}

static void dessine_le_jeu (void) 
{
	int n, v;
	for (n = 0; n < taille; n = n + 1)
		for (v = 0; v < jeu[n]; v = v + 1) dessine_cellule (black, v, n);
}

static int jouer (void) {
	int valeur , ligne;
	selectionne(&valeur, &ligne);
	if  (valeur == STOP_H && ligne == STOP_V) {
		printf ("Le joueur %d abandonne\n", joueur);
		return 0;
	}
	if (joueur == 1) jouer_le_clique(ligne, valeur);
	else {
		jouer_au_hasard();
	}
	return (taille - debut_du_jeu());
}

static void affiche_menu (void)
{
	dessine_cellule (ltGray, STOP_H, STOP_V);
}


int main (int argc, char* argv[]) {
	Rect r; int h, v;
	InitQuickDraw();
	SetRect(&r, 340, 20, 640, 320);
	SetDrawingRect(&r);
	ShowDrawing();
	randSeed = TickCount();
	printf ("
			Bienvenue!
			Le jeu de NIM se joue a deux. 
			Vous êtes le joueur 1, je suis le joueur 2.
			(Je maintiens e'galement l'état du jeu)

			Nous parlons par cliques:

			- Pour obtenir un nouveau jeu (un clique plus a droite augmente la difficulte)
			- Pour jouer, selectionner les cases a griser en selectionnnant la plus a gauche
			- Pour me dire de jouer. 
			- A tout moment le bouton en bas a droite permet d'abandonner

			");
	while (1) {
		efface_ecran();
		affiche_menu();
		printf ("Choisir un nouveau jeu ?\n");
		selectionne (&h,&v);
		if (h == STOP_H && v == STOP_V) {printf ("Au revoir\n"); return 0; }
		if (h < 2) jeu_par_defaut();
		else {
			nouveau_jeu();
			if (h > 6) jouer_avec_intelligence();
		}
		dessine_le_jeu();
		/* test(); */
		printf("Joueur %d commence.\n", joueur);
		while (jouer());
		printf("Le joueur %d a perdu\n", joueur);
	}
}
