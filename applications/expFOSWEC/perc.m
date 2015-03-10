
function perc(A)

ma = max(A);
mi = min(A);
B = [abs(ma),abs(mi)];
mn = mean(B);

diff = (abs(ma)-abs(mi))/mn;

disp([num2str(diff*100) ' %'])

end