type lu=record
        tong:boolean;
        zai1,zai2:integer;
     end;

     huoche=record
            start:integer;
            ending:integer;
            max:longint;
     end;

var input,output:text;
    n,m,p:integer;
    city:array[1..10000, 1..10000] of lu;
    truck:array[1..30000] of huoche;

procedure putin;
var i,j,o,k:integer;
    f:boolean;
begin
 for i:=1 to p do truck[i].max:=-1;
 read(input,m,n);
 readln(input);
 f:=false;
 for i:=1 to n do begin
 read(input,o,k,city[o,k].zai1);
 if (not f) then begin city[o,k].zai2:=city[o,k].zai1;f:=true;end;
 if city[o,k].zai1>city[o,k].zai2 then city[o,k].zai2:=city[o,k].zai1;
 readln(input);
 city[o,k].tong:=true;
 end;
 readln(input,p);
 for i:=1 to p do begin
 read(input,truck[p].start,truck[p].ending);
 readln(input);
 end;
end;

procedure main;
 var canshu1:integer;
begin
 for canshu1:=1 to p do begin
  if city[truck[canshu1].start,truck[canshu1].ending].tong then truck[canshu1].max:=city[truck[canshu1].start,truck[canshu1].ending].zai2;
 end;
end;

procedure putout;
 var sum:integer;
begin
 for sum:=1 to p do writeln(output,truck[sum].max);
end;

begin
 assign(input,'e:\FJ-0381\truck\truck.in');
 assign(output,'e:\FJ-0381\truck\truck.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
