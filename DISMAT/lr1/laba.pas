type t_arr = array[1..50] of integer;

procedure read_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    read(arr[i]);
end;

procedure print_arr(arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    if (arr[i] <> 0) then
      write(arr[i],' ');  
end;

{возвращает "истину", если elem содержится в arr размера n}
function is_elem_in(arr: t_arr; n: integer; elem: integer): boolean;
var i: integer;
    f: boolean;
begin
  f := false;
  is_elem_in := false;
  i := 1;
  
  while (f = false) and (i <= n) do
    begin
      if (elem = arr[i]) then
        begin
          is_elem_in := true;
          f := true;
        end;
      i := i + 1;
    end;  
end;

{возвращает объединение мас-вов arr1 размера n1 и arr2 размера n2}
function union(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  for i := 1 to n1 do
    res[i] := arr1[i];
  
  for i := 1 to n2 do
    if not(is_elem_in(res,n1,arr2[i])) then
      res[i+10] := arr2[i];
      
  union := res;
end;

{возвращает пересечение мас-вов arr1 размера n1 и arr2 размера n2}
function inters(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  for i := 1 to n1 do
    if (is_elem_in(arr2,n2,arr1[i])) then
      res[i] := arr1[i];
    
  inters := res;
end;

{возвращает разность мас-вов arr1 размера n1 и arr2 размера n2}
function subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  for i := 1 to n1 do
    if not(is_elem_in(arr2,n2,arr1[i])) then
      res[i] := arr1[i];
  
  subtract := res;
end;

{возвращает симметричную разность мас-вов arr1 размера n1 и arr2 размера n2}
function sim_subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  for i := 1 to n1 do
    if not(is_elem_in(arr2,n2,arr1[i])) then
      res[i] := arr1[i];
    
  for i := 1 to n2 do
    if not(is_elem_in(arr1,n1,arr2[i])) then
      res[i+10] := arr2[i];

  sim_subtract := res;
end;

var t1,t2,t3: t_arr;
    a,b,c,d: t_arr;
    t4,t5,t6,t7,t8,t9,t10: t_arr;
    a1,b1,c1,d1: t_arr;
    a_b_c: t_arr;

begin
  //программа для задания 1
  writeln('Задание 1');
  writeln('Введите мн-во а');
  read_arr(a,5);
  writeln('Введите мн-во b');
  read_arr(b,4);
  writeln('Введите мн-во c');
  read_arr(c,4);

  t1 := sim_subtract(a,5,b,4);
  t2 := subtract(c,4,a,5);
  t3 := inters(b,4,t1,20);

  d := union(t3,20,t2,20);

  print_arr(d,20);
  
  writeln('');
  //программа для задания 2
  
  writeln('Задание 2');
  writeln('Введите мн-во а');
  read_arr(a1,4);
  writeln('Введите мн-во b');
  read_arr(b1,3);
  writeln('Введите мн-во c');
  read_arr(c1,5);
  
  t4 := union(a1,4,b1,3);
  d := union(c1,5,t4,20);
  
  t5 := inters(a1,4,b1,3);
  a_b_c := inters(t5,10,c1,5);
  
  t6 := inters(a1,4,c1,5);
  t7 := subtract(t6,20,a_b_c,20);
  
  t8 := inters(b1,3,c1,5);
  t9 := subtract(t8,10,a_b_c,20);
  
  t10 := union(t7,25,t9,25);
  d := subtract(d,30,t10,50);
  
  print_arr(d,50);
end.