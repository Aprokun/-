type t_arr = array[1..20] of integer;

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

procedure merge_sort(var arr: t_arr; left: t_arr; lpn: integer; right: t_arr; rpn: integer);
var i: integer;
    lp: integer = 1;
    rp: integer = 1;
begin
  for i := 1 to lpn+rpn do
    if (lp <= lpn) and (left[lp] < right[rp]) then
      begin
        arr[i] := left[lp];
        lp := lp + 1;
      end
    else if (rp <= rpn) then
      begin
        arr[i] := right[rp];
        rp := rp + 1;
      end;
end;

var a,b,c: t_arr;
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
  
  merge_sort(c,a,an,b,bn);
    
  print_arr(c,an+bn);
end.