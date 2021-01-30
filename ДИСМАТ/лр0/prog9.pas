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

procedure merge(var arr: t_out_arr; first, last: integer);
var middle, start, final , j: integer;
    mas: t_out_arr;
begin
  middle:=(first+last) div 2; {делим массив}
  start:=first; {начало левой части}
  final:=middle+1; {начало правой части}
  
  for j:=first to last do {от начала до конца}
    if (start<=middle) and ((final>last) or (arr[start]<arr[final])) then
      begin
        mas[j]:=arr[start];
        inc(start);
      end
    else
      begin
        mas[j]:=arr[final];
        inc(final);
      end;
      
{возвращение результата в список}
for j:=first to last do arr[j]:=mas[j];
end;

procedure merge_sort(var arr: t_out_arr; first, last: integer);
begin
if first<last then
 begin
  merge_sort(arr, first, (first+last) div 2); 
  merge_sort(arr, (first+last) div 2+1, last); 
  merge(arr, first, last);
 end;
end;

var a,b: t_in_arr;
    c: t_out_arr;
  
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  for i := 1 to 10 do
    if is_elem_in(b,a[i]) then
      c[i] := a[i];
    
  merge_sort(c,1,20);
    
  print_arr(c);
end.