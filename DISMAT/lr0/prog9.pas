﻿type  t_arr = array[1..20] of integer;

procedure read_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    read(arr[i]);
end;

procedure print_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    if (arr[i] <> 0) then
      write(arr[i],' ');  
end;

function is_elem_in(arr: t_arr; n: integer; elem: integer): boolean;
var i: integer;
    f: boolean;
begin
  f := false;
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

var a,b,c: t_arr;
    i, j: integer;
    an,bn: integer;
  
begin
  writeln('Введите кол-во элементов множества а, не превышающее 10');
  read(an);
  writeln('Введите элементы множества а');
  read_arr(a,an);
  
  writeln('Введите кол-во элементов множества b, не превышающее 10');
  read(bn);
  writeln('Введите 10 элементов множества b');
  read_arr(b,bn);
    
  for i := 1 to an do
    if (is_elem_in(b,bn,a[i])) then
      c[i] := a[i];
    
  print_arr(c,an+bn);
end.