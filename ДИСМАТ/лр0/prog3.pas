type t_in_arr = array[1..10] of integer;
     t_out_arr = array[1..20] of integer;

procedure read_arr(var arr: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    read(arr[i]);
end;

procedure print_arr(var arr: t_out_arr);
var i: integer;
begin
  for i := 1 to 20 do
    write(arr[i],' ');  
end;

function is_elem_in(arr: t_in_arr; elem: integer): boolean;
var i: integer;
begin
  is_elem_in := false;
  
  for i := 1 to 10 do
    if (elem = arr[i]) then
      is_elem_in := true;  
end;

var a,b: t_in_arr;
    c: t_out_arr;
    i, j: integer;
  
begin
  read_arr(a);
  read_arr(b);
  
  for i := 1 to 10 do
    if not(is_elem_in(b,a[i])) then
      c[i] := a[i];
  
  print_arr(c);
end.