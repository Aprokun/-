const M = 4;
      N = 4;

type t_row = array[1..N] of integer;
     t_p_row = ^t_row;
     t_matr = array[1..M] of t_p_row;
     t_vect = array[1..M] of integer;

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

function is_can_be_sorted(a: t_matr): boolean;
var i,j: byte;
    res: boolean = true;
begin
  i := 1;

  while (i < M) and (res = true) do
    begin
      j := i + 1;

      while (j <= M) and (res = true) do
        begin
          if (a[i]^[1] = a[j]^[1]) then
            res := false;
          
          j := j + 1;
        end;
      
      i := i + 1;
    end;
  
  is_can_be_sorted := res;
end;

procedure sort(var a: t_matr; vect: t_vect);
var i,j: byte;
    key: t_p_row;
    vkey: integer;
begin
  for i := 2 to M do
    begin
      key := a[i];
      vkey := vect[i];
      j := i;
      while (j > 1) and (vect[j-1] < vkey) do
        begin
          a[j] := a[j-1];
          vect[j] := vect[j-1];
          j := j - 1;
        end;
      a[j] := key;
      vect[j] := vkey;
    end;
end;

procedure del_matr(var a: t_matr);
var i: byte;
begin
  for i := 1 to M do
    Dispose(a[i]);
end;

var a: t_matr;
    l,i: integer;
    vect: t_vect;

begin
create_matr(a);

writeln('Ввод матрицы: ');
read_matr(a);

if (is_can_be_sorted(a)) then
  begin
    for i := 1 to M do
      vect[i] := a[i]^[1];
    
    sort(a,vect);
    writeln('Вывод отсортированной матрицы: ');
    write_matr(a);
  end
else
  writeln('Матрицу невозможно отсортировать');

del_matr(a);

read(l);
end.