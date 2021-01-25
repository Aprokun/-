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

procedure iter(arr: t_arr; n: integer; var i_max: integer);
var i: integer;
begin
  i := 1;
  while (i_max = 1) and (i <= n) do
    begin
      if (arr[i] > arr[i_max]) then
        i_max := i;
      i := i + 1;
    end;
end;

var
  n, i_max: integer;
  arr: t_arr;
  
begin
  write('Введите размер последовательности, не превышающий 100: ');
  read(n);
  
  writeln('Вводите последовательность');
  read_arr(arr,n);
  
  i_max := 1;
  
  iter(arr,n,i_max);
  writeln('Результат: ',i_max);
end.