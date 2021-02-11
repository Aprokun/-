{$CODEPAGE UTF-8}

const MAX = 20000;
      N = 4;

type t_row = array[1..MAX div SizeOf(integer)] of integer;
     t_p_row = ^t_row;
     t_max_matr = array[1..MAX div SizeOf(pointer)] of t_p_row;
     t_p_max_matr = ^t_max_matr;

procedure create_matr(var pa: t_p_max_matr; m: byte);
var i: byte;
begin
  GetMem(pa,m*SizeOf(pointer));
  for i := 1 to m do
    New(pa^[i]);
end;

procedure read_matr(pa: t_p_max_matr; m: byte);
var i,j: byte;
begin
  for i := 1 to m do
    for j := 1 to N do
      read(pa^[i]^[j]);
end;

procedure write_matr(pa: t_p_max_matr; m: byte);
var i,j: byte;
begin
  for i := 1 to m do
    begin
      for j := 1 to N do
        write(pa^[i]^[j],' ');
    writeln();
    end;
end;

function is_can_be_sorted(pa: t_p_max_matr; m: byte) : boolean;
var i,j: byte;
    res: boolean = true;
begin
  i := 1;

  while (i < m) and (res = true) do
    begin
      j := i + 1;

      while (j <= m) and (res = true) do
        begin
          if (pa^[i]^[1] = pa^[j]^[1]) then 
            res := false;

          j := j + 1;  
        end;

      i := i + 1;
    end;

  is_can_be_sorted := res;
end;

procedure sort(var pa: t_p_max_matr; m: byte);
var i,j: byte;
    key: t_p_row;
begin
  for i := 2 to m do
    begin
      key := pa^[i];
      j := i;
      while (j > 1) and (pa^[j-1]^[1] < key^[1]) do
        begin
          pa^[j] := pa^[j-1];
          j := j - 1;
        end;
      pa^[j] := key;
    end;

end;

procedure del_matr(var pa: t_p_max_matr; m: byte);
var i: byte;
begin
  for i := 1 to m do
    Dispose(pa^[i]);
  FreeMem(pa,m*SizeOf(pointer));
end;

var pa: t_p_max_matr;
    l,m: integer;

begin
writeln('Введите кол-во строк');
readln(m);

create_matr(pa,m);

writeln('Ввод матрицы: ');
read_matr(pa,m);

if (is_can_be_sorted(pa,m)) then
  begin
    sort(pa,m);

    writeln('Вывод отсортированной матрицы: ');
    write_matr(pa,m);
  end
else
  writeln('Матрица не может быть отсортирована в порядке убывания');

del_matr(pa,m);

read(l);
end.