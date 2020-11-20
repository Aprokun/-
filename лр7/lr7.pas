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

function iter(arr: t_arr; n: integer; var i_max: integer) : integer;
var i: integer;
begin
  i := 1;
  while (i_max = 1) and (i <= n) do
    begin
      if (arr[i_max] < arr[i]) then
        i_max := i;
      i := i + 1;
    end;
  iter := i_max;
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
  
  res := iter(arr,n,i_max);
  writeln('Результат: ',res);
end.