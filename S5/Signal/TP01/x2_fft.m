f_0 = 2;

N = 20;

r = [1/2 1/3 1/4];
r_choisi = 3;

f_e = 50 * N * f_0;
Temps = [0 : 1/f_e : 1-1/f_e];
x_2 = r(r_choisi) * ones(1, length(Temps));


for n = 1 : N
    x_2 = x_2 + ((2 * sin(n * pi * r(r_choisi))) / (n * pi)) * cos(n * pi * 2 * f_0 * Temps);
end

X_2 = fft(x_2);
X_2 = abs(X_2);
Freq = [0 : (f_e / length(Temps)) : f_e - f_e / length(Temps)];

figure
plot(Freq, X_2)
title("x2 pour N = " + N + " et r = " + r(r_choisi))
xlabel("Fréquence")
ylabel("x2")
