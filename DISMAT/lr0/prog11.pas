type t_in_arr = array[1..10] of integer;
     t_out_arr = array[1..20] of integer;

procedure read_arr(var arr: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    read(arr[i]);
end;

function is_elem_in(arr: t_in_arr; elem: integer): boolean;
var i: integer;
begin
  is_elem_in := false;
  
  for i := 1 to 10 do
    if (elem = arr[i]) then
      is_elem_in := true;  
end;

procedure print_arr(arr: t_out_arr);
var i: integer;
begin
  for i := 1 to 20 do
    write(arr[i],' ');  
end;

procedure sort(var arr: t_out_arr);
var i,j,key: integer;
begin
  for i := 2 to 20 do
    begin
      key := arr[i];
      j := i;
      while (j > 1) and (arr[j-1] > key) do
        begin
          arr[j] := arr[j-1];
          j := j - 1;
        end;
      arr[j] := key;  
    end;
end;

var a,b: t_in_arr;
    c: t_out_arr;
    i: integer;
  
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  for i := 1 to 10 do
    if not(is_elem_in(b,a[i])) then
      c[i] := a[i];
    
  for i := 1 to 10 do
    if not(is_elem_in(a,b[i])) then
      c[i+10] := b[i];
  
  sort(c);
    
  print_arr(c);
end.