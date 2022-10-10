f_0 = 2;

N = [2 5 20 100];
N_choisi = 2;

f_e = 50 * N(N_choisi) * f_0;
Temps = [0 : 1/f_e : 1-1/f_e];
x_1 = 1/2 * ones(1, length(Temps));


for n = 1 : N(N_choisi)
    x_1 = x_1 + 2 * (1-(-1)^n) / ((n * pi)^2) * cos(2 * pi * n * f_0 * Temps);
end

figure
plot(Temps, x_1)
title("x1 pour N = " + N(N_choisi))
xlabel("temps")
ylabel("x1")