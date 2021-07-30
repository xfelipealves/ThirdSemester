

A =  [4,1,-1,2;2,2,1,0;1,-1,2,1;1,-1,1,1] ;
b = [4,8,3,1];
n = 4; 

L=eye(n);

for k = 1:(n-1)
  for i= (k+1):n
    m = A(i,k)/A(k,k);
    A(i,k) = 0;
    L(i,k) = m;
    for j = (k+1):n
      A(i,j) = A(i,j) - m * A(k,j);
    endfor;
   endfor;
endfor;
y(1) = b(1);

for i = 2:n
  soma = 0;
  for j = 1:(i-1)
    soma = soma + L(i,j) * y(j);
  endfor;
  y(i) = b(i) - soma;
endfor;
x(n) = y(n)/A(n,n);

for i=(n-1):1
  soma=0;
  for j=(i+1):n
    soma=soma+A(i,j)*x(j);
    endfor;
  x(i)=(y(i)-soma)/A(i,i);
endfor;
A
L
x'
y'