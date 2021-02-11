{$CODEPAGE UTF-8}

const MAX = 20000;

type t_max_row = array[1..MAX div SizeOf(integer)] of integer;
     t_p_max_row = ^t_max_row;
     t_max_matr = array[1..MAX div SizeOf(pointer)] of t_p_max_row;
     t_p_max_matr = ^t_max_matr;

procedure create_matr(var pa: t_p_max_matr; m,n: byte);
var i: byte;
begin
  GetMem(pa,m*SizeOf(pointer));
  for i := 1 to m do
    GetMem(pa^[i],n*SizeOf(integer));
end;

procedure read_matr(pa: t_p_max_matr; m,n: byte);
var i,j: byte;
begin
  for i := 1 to m do
    for j := 1 to n do
      read(pa^[i]^[j]);
end;

procedure write_matr(pa: t_p_max_matr; m,n: byte);
var i,j: byte;
begin
  for i := 1 to m do
    begin
      for j := 1 to n do
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
    key: t_p_max_row;
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

procedure del_matr(var pa: t_p_max_matr; m,n: byte);
var i: byte;
begin
  for i := 1 to m do
    FreeMem(pa^[i],n*SizeOf(integer));
  FreeMem(pa,m*SizeOf(pointer));
end;

var a: t_p_max_matr;
    l,m,n: integer;

begin
writeln('Введите кол-во строк');
readln(m);

writeln('Введите кол-во элементов в строке');
readln(n);

create_matr(a,m,n);

writeln('Ввод матрицы: ');
read_matr(a,m,n);

if (is_can_be_sorted(a,m)) then
  begin
    sort(a,m);

    writeln('Вывод отсортированной матрицы: ');
    write_matr(a,m,n);
  end
else
  writeln('Матрица не может быть отсортирована в порядке убывания');

del_matr(a,m,n);

read(l);
end.