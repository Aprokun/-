type
  t_arr = array[1..50] of integer;
  t_arr_bln = array[1..50] of boolean;

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
//начало блока вспомогательных функций
//

{возвращает массив с элементами логического типа, где значение "истина" - 
элементы массива arr размера n присутствующие в универсуме u размера un}
function to_bln_arr(arr: t_arr; n: integer; u: t_arr; un: integer): t_arr_bln;
var i: byte;
    res: to_arr_bln;
begin
  for i := 1 to n do
    if (is_elem_in(u,un,arr[i])) then
      res[i] := true;
end;

//
//конец блока вспомогательных функций
//

//
//начало блока основных функций операций над мн-вами
//

{возвращает "истину", если мас-в arr2 размера n2 включает в 
себя мас-в arr1 размера n1, иначе - "ложь"}
function isInclude(arr1: t_arr_bln; arr2: t_arr_bln; un: integer): boolean;
var
  i: byte = 1;
  f: boolean = true;
begin
  while (f = true) and (i <= un) do
  begin
    f := arr1[i] <= arr2[i];
    i := i + 1;
  end;
  isInclude := f;
end;

{возвращает объединение мас-вов arr1 размера n1 и arr2 размера n2}
function union(arr1: t_arr; arr2: t_arr; un: integer): t_arr_bln;
var
  res: t_arr_bln;
  i: byte;
begin
  for i := 1 to un do
    res[i] := (arr1[i] or arr2[i]);
  
  union := res;
end;

{возвращает пересечение мас-вов arr1 размера n1 и arr2 размера n2}
function inters(arr1: t_arr; arr2: t_arr; un: integer): t_arr;
var
  res: t_arr;
  i: byte;
begin
  for i := 1 to un do
    res[i] := arr1[i] and arr2[i];
  
  inters := res;
end;

{возвращает разность мас-вов arr1 размера n1 и arr2 размера n2}
function subtract(arr1: t_arr_bln; arr2: t_arr_bln; un: integer): t_arr;
var
  res: t_arr_bln;
  i: byte;
begin
  for i := 1 to un do
    res[i] := (arr1[i] > arr2[i]);
  
  subtract := res;
end;

{возвращает симметричную разность мас-вов arr1 размера n1 и arr2 размера n2}
function sim_subtract(arr1: t_arr_bln; arr2: t_arr_bln; un: integer): t_arr;
var
  res: t_arr_bln;
  i: byte;
begin
  for i := 1 to un do
    res[i] := arr1[i] <> arr2[i];
  
  sim_subtract := res;
end;

//
//конец блока основных функций операций над мн-вами
//

var
  u: t_arr;
  un: integer;
  a: t_arr;
  an: integer;

begin
  writeln('Введите размер универсума, не превышающий 10');
  read(un);
  writeln('Введите универсум');
  read_arr(u,un);
  
  writeln('Введите размер мн-ва элементов,не превышающий 10');
  read(an);
  writeln('Введите мн-во элементов');
  read_arr(a,an);
  
  to_bln_arr(a,an,u,un);
end.