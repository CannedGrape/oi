program scholar1;
type arr1=array[0..5] of integer;
var record1:array [0..350] of arr1;
   {[0]：学号  [1]：语文   [2]：数学  [3]：英语 [4]：总分}
    file1:string[20];
    text1,text2:text;
    n:integer;
procedure readdata_scholar; {输入原始数据}
var i,j:integer;
begin
  writeln('input filename for input:');
  readln(file1);
  assign(text1,file1); reset(text1);
  readln(text1,n);
  for i:=1 to n  do
   begin
     for j:=1 to 3 do
       read(text1,record1[i][j]);
     readln(text1);
   end;
  close(text1);
end;

procedure sort1;
var  i,j,k,tmp1,tmp2:integer;
begin
 for i:=1 to n-1 do
  begin
    tmp1:=i;
    for j:=i+1 to n do
      if (record1[tmp1][4]<record1[j][4]) then
          tmp1:=j
      else
        if (record1[tmp1][4]=record1[j][4]) and (record1[tmp1][1]<record1[j][1]) then
          tmp1:=j
        else
          if (record1[tmp1][4]=record1[j][4]) and (record1[tmp1][1]=record1[j][1])
                   and (record1[tmp1][0]>record1[j][0]) then
             tmp1:=j;
   for k:=0 to 4 do
     begin
      tmp2:=record1[i][k];
      record1[i][k]:=record1[tmp1][k];
      record1[tmp1][k]:=tmp2;
     end;
   end;
 end;

procedure calcul;
var i,j:integer;
begin
  for i:=1 to n do
   begin
     record1[i][0]:=i;
     record1[i][4]:=0;
     for j:=1 to 3 do
       record1[i][4]:=record1[i][4]+record1[i][j];
    end;
  sort1;
 end;
procedure out_scholar;
var i:integer;
begin
  writeln('input filename for output:');
  readln(file1);
  assign(text2,file1); rewrite(text2);
  for i:=1 to 5  do
    begin
      write(text2,record1[i][0],' ',record1[i][4]);
      writeln(text2);
    end;
  close(text2);
end;
begin  { main}
   readdata_scholar;
   calcul;
   out_scholar;
end.

