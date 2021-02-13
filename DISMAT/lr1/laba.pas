type t_arr = array[1..50] of integer;

//
//блок процедур ввода и вывода мас-ов
//

procedure read_arr(var arr: t_arr; n: integer);
var i: byte;
begin
  for i := 1 to n do
    read(arr[i]);
end;

procedure print_arr(arr: t_arr; n: integer);
var i: byte;
begin
  for i := 1 to n do
    if (arr[i] <> 0) then
      write(arr[i],' ');  
end;

//
//конец блока процедур ввода и вывода мас-ов
//

//
//начало блока вспомогательных функций
//

{возвращает "истину", если мас-в arr размера n отсортирован по возрастанию}
function isSortedByAscending(arr: t_arr; n: integer): boolean;
var i: byte = 1;
    f: boolean = true;
begin
  isSortedByAscending := true;
  
  while (f = true) and (i < n) do
    begin
      if (arr[i] >= arr[i+1]) then
        begin
          f := false;
          isSortedByAscending := false
        end;
      i := i + 1;
    end;
end;

{возвращает "истину", если elem содержится в arr размера n, иначе - "ложь"}
function is_elem_in(arr: t_arr; n: integer; elem: integer): boolean;
var i: byte;
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

function merge_sort(left: t_arr; lpn: integer; right: t_arr; rpn: integer): t_arr;
var i: byte;
    lp: byte = 1;
    rp: byte = 1;
    res: t_arr;
begin
  for i := 1 to lpn+rpn do
    if (lp <= lpn) and (left[lp] < right[rp]) then
      begin
        res[i] := left[lp];
        lp := lp + 1;
      end
    else if (rp <= rpn) then
      begin
        res[i] := right[rp];
        rp := rp + 1;
      end;
      
  merge_sort := res;
end;

function bin_search(arr: t_arr; n: integer; elem: integer): boolean;
var i,left,right,mid: byte;
    f: boolean = false;
begin
  left := 1;
  right := n;
  bin_search := false;
  
  while (left <= right) and (f = false) do
    begin
      mid := (left + right) div 2;
      
      if (elem < arr[mid]) then
        right := mid - 1
      else if (elem > arr[mid]) then
        left := mid + 1
      else
        begin
          bin_search := true;
          f := true;
        end;
    end;
end;

//
//конец блока вспомогательных функций
//

//
//начало блока основных функций операций над мн-вами
//

{возвращает "истину", если мас-в arr2 размера n2 включает в себя мас-в arr1 размера n1, иначе - "ложь"}
function isInclude(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): boolean;
var i: byte;
    f: boolean;
begin
  isInclude := true;
  
  if (isSortedByAscending(arr1,n1) and isSortedByAscending(arr2,n2)) then
    begin
      while (f = true) and (i <= n1) do
        begin
          if not(bin_search(arr2,n2,arr1[i])) then
            begin
              f := false;
              isInclude := false;
            end;
          
          i := i + 1;
        end;
    end
  else
    begin
      while (f = true) and (i <= n1) do
        begin
          if not(is_elem_in(arr2,n2,arr1[i])) then
            begin
              f := false;
              isInclude := false;
            end;
      
          i := i + 1;
        end;
    end;
end;

{возвращает "истину", если мас-в arr2 размера n2 строго включает в себя мас-в arr1 размера n1, иначе - "ложь"}
function isStrictInclude(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): boolean;
var i: byte;
    f: boolean;
begin
  if (isInclude(arr1,n1,arr2,n2)) then
    if (n1 <> n2) then
      isStrictInclude := true
    else
      isStrictInclude := false;
end;

{возвращает объединение мас-вов arr1 размера n1 и arr2 размера n2}
function union(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: byte;
begin
  if (isSortedByAscending(arr1,n1) and isSortedByAscending(arr2,n2)) then
    begin
      res := merge_sort(arr1,n1,arr2,n2);
    end
  else
    begin
      for i := 1 to n1 do
        res[i] := arr1[i];
  
      for i := 1 to n2 do
        if not(is_elem_in(res,n1,arr2[i])) then
          res[i+10] := arr2[i];
    end;    
  union := res;
end;

{возвращает пересечение мас-вов arr1 размера n1 и arr2 размера n2}
function inters(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: byte;
begin
  if (isSortedByAscending(arr1,n1) and isSortedByAscending(arr1,n1)) then
    begin
      for i := 1 to n1 do
        if (bin_search(arr2,n2,arr1[i])) then
          res[i] := arr1[i];  
    end
  else
    begin
      for i := 1 to n1 do
        if (is_elem_in(arr2,n2,arr1[i])) then
          res[i] := arr1[i];
    end;
    
  inters := res;
end;

{возвращает разность мас-вов arr1 размера n1 и arr2 размера n2}
function subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: byte;
begin
  if (isSortedByAscending(arr1,n1) and isSortedByAscending(arr2,n2)) then
    begin
      for i := 1 to n1 do
        if not(bin_search(arr2,n2,arr1[i])) then
          res[i] := arr1[i];      
    end
  else
    begin
      for i := 1 to n1 do
        if not(is_elem_in(arr2,n2,arr1[i])) then
          res[i] := arr1[i];
    end;
  subtract := res;
end;

{возвращает симметричную разность мас-вов arr1 размера n1 и arr2 размера n2}
function sim_subtract(arr1: t_arr; n1: integer; arr2: t_arr; n2: integer): t_arr;
var res: t_arr;
    i: byte;
begin
  if (isSortedByAscending(arr1,n1) and isSortedByAscending(arr2,n2)) then
    begin
      for i := 1 to n1 do
        if not(bin_search(arr2,n2,arr1[i])) then
          res[i] := arr1[i];
      
      for i := 1 to n2 do
        if not(bin_search(arr1,n1,arr2[i])) then
          res[i] := arr2[i];
    end
  else
    begin
      for i := 1 to n1 do
        if not(is_elem_in(arr2,n2,arr1[i])) then
          res[i] := arr1[i];
    
      for i := 1 to n2 do
        if not(is_elem_in(arr1,n1,arr2[i])) then
          res[i+10] := arr2[i];  
    end;
    
  sim_subtract := res;
end;

//
//конец блока основных функций операций над мн-вами
//

var t1,t2,t3: t_arr;
    a,b,c,d: t_arr;
    
    t4,t5,t6,t7,t8: t_arr;
    a1,b1,c1,d1: t_arr;
    aNb: t_arr;

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
  
  //находим объединение всех областей
  t4 := union(a1,4,b1,3);
  d := union(c1,5,t4,20);
  
  //находим пересечение A с B
  aNb := inters(a1,4,b1,3);
  
  //находим объединение пересечений A с С и В с С
  t5 := inters(a1,4,c1,5);
  t6 := inters(b1,3,c1,5);
  t7 := union(t5,10,t6,10);
  
  //вычитаем из объединения пересечений А с С и В с С область пересечения А с В
  t8 := subtract(t7,20,aNb,10);
  
  //находим итоговое значение
  d := subtract(d,25,t8,25);
  print_arr(d,50);
end.