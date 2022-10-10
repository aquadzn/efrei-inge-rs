% fichier d'initialisation pour la quantification

%signal sinusoïdal
f0 = 1;   %frequence du signal
A0 = 1.5; %amplitude du signal
phi0 = 0; %dephasage du signal

% bruit à bande limitee

Bwn = 10.5;
Vwn = 1;

%signal en dent de scie
f1 = 1.3;
A1 = 1;

%echantillonneur bloqueur
fe = 15;

%quantificateur
Aq = 2;         %amplitude
b = 4;          %nombre de bit de codage 
q = 2*Aq/(2^b); %pas de quantification