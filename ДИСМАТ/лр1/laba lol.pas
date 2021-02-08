type t_arr = array[1..10] of integer;

function is_elem_in(arr: t_arr; n: integer; elem: integer): boolean;
var i: integer;
    f: boolean;
begin
  f := false;
  i := 1;
  
  while (f = false) do
    begin
      if (elem = arr[i]) and (i <= n) then
        begin
          is_elem_in := true;
          f := true;
        end;
      i := i + 1;
    end;  
end;

function union(arr1: t_arr; arr1n: integer; arr2: t_arr; arr2n: integer): t_arr;
var res: t_arr;
    j: integer = 1;
    i: integer;
begin
  for i := 1 to arr1n do
    res[i] := arr1[i];
  
  for i := 1 to arr2n do
    if not(is_elem_in(res,arr1n,arr2[i])) then
      begin
        res[j+10] := arr2[i];
        j := j + 1;
      end;
      
  union := res;
end;

function inters(arr1: t_arr; arr1n: integer; arr2: t_arr; arr2n: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  for i := 1 to 10 do
    if (is_elem_in(arr2,arr2n,arr1[i])) then
      res[i] := arr1[i];
    
  inters := res;
end;

function subtract(arr1: t_arr; arr1n: integer; arr2: t_arr; arr2n: integer): t_arr;
var res: t_arr;
    i: integer;
begin
  
end;




begin
  
end.