{$CODEPAGE UTF-8}

const MAX = 20000;
      M = 4;

type t_max_row = array[1..MAX div SizeOf(integer)] of integer;
     t_p_max_row = ^t_max_row;
     t_matr = array[1..M] of t_p_max_row;

procedure create_matr(var a: t_matr; n: byte);
var i: byte;
begin
  for i := 1 to M do
    GetMem(a[i],n * SizeOf(integer));
end;

procedure read_matr(a: t_matr; n: byte);
var i,j: byte;
begin
  for i := 1 to M do
    for j := 1 to n do
      read(a[i]^[j]);
end;

procedure write_matr(a: t_matr; n: byte);
var i,j: byte;
begin
  for i := 1 to M do
    begin
      for j := 1 to n do
        write(a[i]^[j],' ');
    writeln();
    end;
end;

procedure sort(var a: t_matr);
var i,j: byte;
    key: t_p_max_row;
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

procedure del_matr(var a: t_matr; n: byte);
var i: byte;
begin
  for i := 1 to M do
    FreeMem(a[i],n * SizeOf(integer));
end;

var a: t_matr;
    l,n: integer;

begin
writeln('Введите кол-во элементов в строке');
readln(n);

create_matr(a,n);

writeln('Ввод матрицы: ');
read_matr(a,n);

sort(a);

writeln('Вывод отсортированной матрицы: ');
write_matr(a,n);

del_matr(a,n);

read(l);
end.