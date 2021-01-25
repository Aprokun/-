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

procedure recu(arr: t_arr; n: integer;  var i_max: integer);
begin
  n := n - 1;
  if (n > 1) then
    begin
      recu(arr,n,i_max);
      if (arr[n] > arr[i_max]) and (i_max = 1) then
        i_max := n;
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
  
  n := n + 1;
  i_max := 1;
  
  recu(arr,n,i_max);
  writeln('Результат:',i_max);
end.