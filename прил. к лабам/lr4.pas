const
  SIZE = 100;
type
  t_arr = array [1..SIZE] of integer;

{процедура ввода множества}
procedure read_arr(var arr: t_arr; n: integer);
var
  i: integer;
begin
  for i := 1 to n do
    read(arr[i]);
end;

{процедура вывода множества}
procedure write_arr(arr: t_arr; n: integer);
var
  i: integer;
begin
  for i := 1 to n do
    write(arr[i], ' ');
end;

{процедура проверки на принадлежность множества arr1 множеству arr2}
function is_subarr(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer) : boolean;
var
  i,j: integer;
  flag: boolean;
  res: boolean;
begin
  res := true;
  for i := 1 to n1 do
    begin
      flag := false;
      for j := 1 to n2 do
        if (arr1[i] = arr2[j]) then
          flag := true;
      if (flag = false) then
        res := false;
    end;
    is_subarr := res;
end;

{процедура сортировки множества в порядке неубывания}
procedure sort_arr(var arr: t_arr; n: integer);
var
  i, j: integer;
  t: integer;
begin
  for i := 1 to n - 1 do
    for j := i + 1 to n do
      if (arr[i] > arr[j]) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;
      end;
end;

var
  arr1, arr2: t_arr;
  n1, n2: integer;

begin
  write('Введите размер первого множества (размер не превышает 100): ');
  read(n1);
  writeln('Вводите значения первого множества');
  read_arr(arr1, n1);
  
  
  write('Введите размер второго множества (размер не превышает 100): ');
  read(n2);
  writeln('Вводите значения второго множества');
  read_arr(arr2, n2);
  
  if (n1 > n2) then
    begin
      if (is_subarr(arr2, n2, arr1, n1) = true) then
        sort_arr(arr2, n2); 
    end
  else if (n2 > n1) then
    begin
      if (is_subarr(arr1, n1, arr2, n2) = true) then
        sort_arr(arr1, n1);
    end
  else
    begin
      if (is_subarr(arr1, n1, arr2, n2) = true) then
        begin
          sort_arr(arr1, n1);
          sort_arr(arr2, n2);
        end;
    end;
  
  writeln('Вывод итоговых последовательностей');
  
  writeln('Значения первого множества');
  write_arr(arr1, n1);
  
  writeln(' ');
  
  writeln('Значения второго множества');
  write_arr(arr2, n2);
end.

