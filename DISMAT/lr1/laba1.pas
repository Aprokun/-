type
  t_arr = array[1..50] of integer;

//
//блок процедур ввода и вывода мас-ов
//

procedure read_arr(var arr: t_arr; n: integer);
var
  i: byte;
begin
  for i := 1 to n do
    read(arr[i]);
end;

procedure print_arr(arr: t_arr; n: integer);
var
  i: byte;
begin
  for i := 1 to n do
    if (arr[i] <> 0) then
      write(arr[i], ' ');  
end;

//
//конец блока процедур ввода и вывода мас-ов
//

//
//начало блока основных функций операций над мн-вами
//

{возвращает "истину", если мас-в arr2 размера n2 включает в себя мас-в arr1 размера n1, иначе - "ложь"}
function isInclude(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): boolean;
var
  i: byte = 1;
  j: byte = 1;
  f: boolean = true;
begin
  isInclude := true;
  
  while (f = true) and (i <= n1) do
    begin
      if (arr1[i] = arr2[j]) then
        begin
          i := i + 1;
          j := j + 1;
        end
      else 
        if (arr1[i] > arr2[j]) then
          j := j + 1
        else
          f := false;
    end;
end;

{возвращает "истину", если мас-в arr2 размера n2 строго включает в себя мас-в arr1 размера n1, иначе - "ложь"}
function isStrictInclude(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): boolean;
var
  i: byte;
  f: boolean;
begin
  if (isInclude(arr1, n1, arr2, n2)) then
    if (n1 <> n2) then
      isStrictInclude := true
    else
      isStrictInclude := false;
end;

{возвращает объединение мас-вов arr1 размера n1 и arr2 размера n2}
function union(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var
  res: t_arr;
  i: byte = 1;
  j: byte = 1;
  k: byte = 0;
begin
  while (i <= n1) and (j <= n2) do
    begin
      k := k + 1;
      
      if (arr1[i] = arr2[j]) then
        begin
          res[k] := arr1[i];
          i := i + 1;
          j := j + 1;
        end
      else
        if (arr1[i] > arr2[j]) then
          begin
            res[k] := arr2[j];
            j := j + 1;
          end
        else
          begin
            res[k] := arr1[i];
            i := i + 1;
          end;
    end;
  
  while (i <= n1) do
    begin
      k := k + 1;
      res[k] := arr1[i];
      i := i + 1;
    end;
    
  while (j <= n2) do
    begin
      k := k + 1;
      res[k] := arr2[j];
      j := j + 1;
    end;
     
  union := res;
end;

{возвращает пересечение мас-вов arr1 размера n1 и arr2 размера n2}
function inters(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var
  res: t_arr;
  i: byte = 1;
  j: byte = 1;
  k: byte = 0;
begin
  while (i <= n1) and (j <= n2) do
    begin
      if (arr1[i] = arr2[j]) then
        begin
          k := k + 1;
          res[k] := arr1[i];
          i := i + 1;
          j := j + 1;
        end
      else
        if (arr1[i] > arr2[j]) then
          j := j + 1
        else
          i := i + 1;
    end;
  
  inters := res;
end;

{возвращает разность мас-вов arr1 размера n1 и arr2 размера n2}
function subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var
  res: t_arr;
  i: byte = 1;
  j: byte = 1;
  k: byte = 0;
begin
  while (i <= n1) and (j <= n2) do
    begin
      if (arr1[i] = arr2[j]) then
        begin
          i := i + 1;
          j := j + 1;
        end
      else
        if (arr1[i] > arr2[j]) then
          j := j + 1
        else
          begin
            k := k + 1;
            res[k] := arr1[i];
            i := i + 1;
          end;
    end;
    
  while (i <= n1) do
    begin
      k := k + 1;
      res[k] := arr1[i];
      i := i + 1;
    end;
  
  subtract := res;
end;

{возвращает симметричную разность мас-вов arr1 размера n1 и arr2 размера n2}
function sim_subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var
  res: t_arr;
  a,b: t_arr;
  i: byte = 1;
  j: byte = 1;
  k: byte = 0;
begin
  while (i <= n1) and (j <= n2) do
    begin
      if (arr1[i] = arr2[j]) then
        begin
          i := i + 1;
          j := j + 1;
        end
      else
        if (arr1[i] > arr2[j]) then
          begin
            k := k + 1;
            res[k] := arr2[j];
            j := j + 1;
          end
        else
          begin
            k := k + 1;
            res[k] := arr1[i];
            i := i + 1;
          end;
    end;
  
  while (i <= n1) do
   begin
     k := k + 1;
     res[k] := arr1[i];
     i := i + 1;
   end;
   
   while (j <= n2) do
    begin
      k := k + 1;
      res[k] := arr2[j];
      j := j + 1;
    end;
  
  sim_subtract := res;
end;

//
//конец блока основных функций операций над мн-вами
//

var
  t1, t2, t3: t_arr;
  a, b, c, d: t_arr;
  
  t4, t5, t6, t7, t8: t_arr;
  a1, b1, c1, d1: t_arr;
  aNb: t_arr;

begin
  //программа для задания 1
  writeln('Задание 1');
  writeln('Введите мн-во а');
  read_arr(a, 5);
  writeln('Введите мн-во b');
  read_arr(b, 4);
  writeln('Введите мн-во c');
  read_arr(c, 4);
  
  t1 := sim_subtract(a, 5, b, 4);
  t2 := subtract(c, 4, a, 5);
  t3 := inters(b, 4, t1, 5);
  
  d := union(t3, 2, t2, 3);
  
  print_arr(d, 20);
  
  writeln('');
  //программа для задания 2
  
  writeln('Задание 2');
  writeln('Введите мн-во а');
  read_arr(a1, 4);
  writeln('Введите мн-во b');
  read_arr(b1, 3);
  writeln('Введите мн-во c');
  read_arr(c1, 5);
  
  //находим объединение всех областей
  t4 := union(a1, 4, b1, 3);
  d := union(c1, 5, t4, 6);
  
  //находим пересечение A с B
  aNb := inters(a1, 4, b1, 3);
  
  //находим объединение пересечений A с С и В с С
  t5 := inters(a1, 4, c1, 5);
  t6 := inters(b1, 3, c1, 5);
  t7 := union(t5, 2, t6, 2);
  
  //вычитаем из объединения пересечений А с С и В с С область пересечения А с В
  t8 := subtract(t7, 4, aNb, 1);
  
  //находим итоговое значение
  d := subtract(d, 12, t8, 2);
  print_arr(d, 50);
end.