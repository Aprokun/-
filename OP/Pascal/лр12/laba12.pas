const M = 4;
      N = 4;

type t_row = array[1..N] of integer;
     t_p_row = ^t_row;
     t_matr = array[1..M] of t_p_row;

procedure create_matr(var a: t_matr);
var i: byte;
begin
  for i := 1 to M do
    New(a[i]);
end;

procedure read_matr(a: t_matr);
var i,j: byte;
begin
  for i := 1 to M do
    for j := 1 to N do
      read(a[i]^[j]);
end;

procedure write_matr(a: t_matr);
var i,j: byte;
begin
  for i := 1 to M do
    begin
      for j := 1 to N do
        write(a[i]^[j],' ');
    writeln();
    end;
end;

procedure sort(var a: t_matr);
var i,j: byte;
    key: t_p_row;
begin
  for i := 2 to M do
    begin
      key := a[i];
      j := i;
      while (j > 1) and (a[j-1]^[1] < key^[1]) do
        begin
          a[j] := a[j-1];
          j := j - 1;
        end;
      a[j] := key;
    end;
end;

procedure del_matr(var a: t_matr);
var i: byte;
begin
  for i := 1 to M do
    Dispose(a[i]);
end;

var a: t_matr;
    l: integer;

begin
create_matr(a);

writeln('Ввод матрицы: ');
read_matr(a);

sort(a);

writeln('Вывод отсортированной матрицы: ');
write_matr(a);

del_matr(a);

read(l);
end.