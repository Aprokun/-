var x,y,z:real;
    a,b,a2:real;
    sqrt3_cos5_x:real;
begin
  writeln('Введите x,y,z');
  write('x = ');
  read(x);
  write('y = ');
  read(y);
  write('z = ');
  read(z);
  sqrt3_cos5_x := exp(ln(abs(cos(x)))*(5/3));
  a := (28*sqrt3_cos5_x-595*z)/(10000+70000*exp(x+y));
  b := x - (z*z)/(y-5) + 0.125 + exp(-2*z);
  writeln(' ':40,'При x = ',x:0:3,' y = ',y:0:3,' z = ',z:0:3);
  writeln(' ':40,'a = ',a:5:10);
  writeln(' ':40,'b = ',b:5:10);
end.