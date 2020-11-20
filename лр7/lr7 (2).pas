const
  SIZE = 100;
type
  t_arr = array[1..SIZE] of integer;
  
procedure read_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    read(arr[i]);  
end;

function recu(arr: t_arr; n: integer; var i_max: integer; i: integer) : integer;
begin
  i := i + 1;
  if (i <= n) then
    begin
      recu(arr,n,i_max,i);
      if (arr[i] > arr[i_max]) and (i_max = 1) then
        i_max := n;
      recu := i_max;
    end;
end;

function iter_recu(arr: t_arr; n: integer; var i_max: integer) : integer;
var i: integer;
begin
  i := 0;
  iter_recu := recu(arr,n,i_max,i);
end;

var
  n: integer;
  arr: t_arr;
  i_max,res: integer;
  
begin
  write('Введите размер последовательности, не превышающий 100: ');
  read(n);
  
  writeln('Вводите последовательность');
  read_arr(arr,n);
  
  i_max := 1;
  
  res := iter_recu(arr,n,i_max);
  writeln('Результат:',res);
end.