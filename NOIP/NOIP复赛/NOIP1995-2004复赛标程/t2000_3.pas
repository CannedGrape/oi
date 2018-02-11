program t2000_3(input,output);
const maxn=20;
type arr=array[1..maxn] of 0..2;
var
   h:string;{h中存储输入的龙的开始字符;}
   s:array[1..maxn] of string;{s[1..n]存储输入的n个单词}
   max,I,j,n,total:integer;{max最大长度；total从某个单词开始的最大长度;n单词个数}
   ad:array[1..maxn,1..maxn] of integer;
   count:arr;   {每个单词能使用的数量，最多为2}

function addition(I,j:integer):integer;{单词s[I]后面接s[j]，能增加的长度}
var Li,Lj,tj:integer;{Li单词s[I]的长度；Lj单词s[j]的长度；tj：与s[I]中最后一个字符相同的，单词s[j]中的字符位置；}
     hi,hj:integer;{hi单词s[I]中的指针，从最后一个位置朝前；hj单词s[j]中的指针，从tj位置朝前}
     find:boolean;{find为true，找到匹配}
begin
    Li:=length(s[I]);Lj:=length(s[j]);
    tj:=1;find:=false;
    while (tj<Lj) and (tj<Li) and not find do begin{tj=Li时，可能出现包含关系}
        while (tj<Lj) and (tj<Li) and (s[I][Li]<>s[j][tj]) do
                      tj:=tj+1;
        if (tj<Lj) and (tj<Li) then begin
            hj:=tj;hi:=Li;
            while (hj>0) and (s[I][hi]=s[j][hj]) do begin
                  hi:=hi-1;
                  hj:=hj-1;
            end;
            if hj=0 then find:=true{若s[j]从第tj个至第1个都在s[I]中有相同值，则s[I]可接s[j]}
               else tj:=tj+1;{准备寻找下一个与s[I]最后一个字符相同的tj位置}
        end;
   end;
   if find then addition:=Lj-tj{增加量}
       else addition:=0;
end;

function try(count:arr;i:integer):integer;
var total,max,j:integer;
begin
   max:=0;
   for j:=1 to n do
   if (count[j]<2) and (ad[i,j]<>0) then begin
      count[j]:=count[j]+1;
      total:=try(count,j)+ad[i,j];
      if max<total then max:=total;
      count[j]:=count[j]-1;
   end;
   try:=max;
end;

begin
    assIgn(input,'4.in');reset(input);
    readln(n);
    for I:=1 to n do readln(s[I]);
    readln(h);
    close(input);
    for I:=1 to n do
      for j:=1 to n do ad[I,j]:=addition(I,j);
    max:=0;
    for I:=1 to n do begin
       for j:=1 to n do count[j]:=0;
       count[i]:=1;
       if s[I][1]=h[1] then begin
            total:=try(count,i)+length(s[i]);
            if max<total then max:=total;end;
    end;
    assign(output,'4.out');
    rewrite(output);
    writeln(max);
    close(output);
end.
