{$A-,B-,D-,E-,F-,G-,I-,L-,N-,O-,P-,Q-,R-,S-,T-,V-,X-,Y-}
{$M 8192,0,655360}
program NOIPG2;
  const maxn=2300;
  type
    node=record{定义节点数据类型}
           str:string[115];dep:byte;
         end; {str表示字串，其长度不会超过115（长度超过115的字串
     不可能通过变换成为目标字串，因为题目限定变换10次之内，且串长
     不超过20，即起始串最多可经过5次变换时增长，中间串的最大长度
     为20+5*19=115，否则经过余下的步数不可能变为长度不超过20的
     目标串），dep表示深度}
    ctype=array[1..maxn]of ^node;
    bin=0..1;
  var
    maxk:byte;c:array [0..1]of ctype;
    x0:array[0..6,0..1]of string[20];
    filename:string;
    open,closed:array [0..1] of integer;
  procedure Init;{读取数据，初始化}
    var f:text;temp:string;i,j:integer;
    begin
      for i:=0 to 1 do
        for j:=1 to maxn do new(c[i,j]);
      write('Input filename:');readln(filename);
      assign(f,filename);reset(f);i:=0;
      while not eof(f) and (i<=6) do begin
        readln(f,temp);
        x0[i,0]:=copy(temp,1,pos(' ',temp)-1);
        x0[i,1]:=copy(temp,pos(' ',temp)+1,length(temp));
        inc(i);
      end;
      maxk:=i-1;close(f);
    end;
  procedure calc;
    var i,j,k:integer;st:bin;
        d:string;f:text;
    procedure bool(st:bin);{判断是否到达目标状态或双向搜索相遇}
      var i:integer;
      begin
        if x0[0,1-st]=c[st,closed[st]]^.str then begin
          {如果到达目标状态，则输出结果，退出}
          writeln(c[st,closed[st]]^.dep);
          halt;
        end;
        for i:=1 to closed[1-st] do
          if c[st,closed[st]]^.str=c[1-st,i]^.str then begin
            {如果双向搜索相遇（即得到同一节点），
             则输出结果（2个方向搜索的步数之和），退出}
            writeln(c[st,closed[st]]^.dep+c[1-st,i]^.dep);
            halt;
          end;
      end;
    procedure checkup(st:bin);{判断节点是否与前面重复}
      var i:integer;
      begin
        for i:=1 to closed[st]-1 do
          if c[st,i]^.str=c[st,closed[st]]^.str then begin
            dec(closed[st]);exit;{如果节点重复，则删除本节点}
          end;
        bool(st);{如果节点不重复，再判断是否到达目标状态}
      end;
    procedure expand(st:bin);{扩展产生新节点}
      var i,j,k,lx,ld:integer;
      begin
        inc(open[st]);d:=c[st,open[st]]^.str;{队首节点出队}
        k:=c[st,open[st]]^.dep;ld:=length(d);
        for i:=1 to maxk do begin
          {从队首节点（父节点）出发产生新节点（子节点）}
          lx:=length(x0[i,st]);
          for j:=1 to ld do begin
            if (copy(d,j,lx)=x0[i,st]) and (length(copy(d,1,j-1)+x0[i,1-st]
               +copy(d,j+lx,ld))<=115) then begin
            {如果新节点的串长超过115，则不扩展！即剪掉此枝}
              if closed[st]>=maxn then exit;{如果队列已满，只好退出}
              inc(closed[st]);{新节点入队}
              c[st,closed[st]]^.str:=copy(d,1,j-1)+x0[i,1-st]+copy(d,j+lx,ld);
              c[st,closed[st]]^.dep:=k+1;{子节点深度=父节点深度+1}
              checkup(st);{检查新节点是否重复}
            end;
          end;
        end;
      end;
    Begin
      for st:=0 to 1 do begin{正向(st=0)逆向(st=1)搜索节点队列初始化}
        open[st]:=0;closed[st]:=1;
        c[st,closed[st]]^.str:=x0[0,st];c[st,closed[st]]^.dep:=0;
        bool(st);
      end;
      repeat
        {选择节点数较少且队列未空、未满、深度未达到10的方向先扩展}
        if (open[0]<=open[1]) and not ((open[0]>=closed[0]) or
          (closed[0]>=maxn) or (c[0,closed[0]]^.dep>10)) then expand(0);
        if (open[1]<=open[0]) and not ((open[1]>=closed[1]) or
          (closed[1]>=maxn) or (c[1,closed[1]]^.dep>10)) then expand(1);
       {如果一方搜索终止，继续另一方的搜索，直到两个方向都终止}
       if not ((open[0]>=closed[0]) or (closed[0]>=maxn) or
          (c[0,closed[0]]^.dep>10)) then expand(0);
        if not ((open[1]>=closed[1]) or (closed[1]>=maxn) or
          (c[1,closed[1]]^.dep>10)) then expand(1);
      until (open[0]>=closed[0]) or (c[0,closed[0]]^.dep>10) or (closed[0]>=maxn)
          and (closed[1]>=maxn) or (open[1]>=closed[1]) or (c[1,closed[1]]^.dep>10);
       {终止条件：任一方队空（无解）或搜索深度超过10（10步内无解）
        或双方均溢出（可能有解也可能无解，应尽量避免，要尽量把节
        点数组开大一点，采用双向搜索，采取剪枝措施等）}
    End;
  BEGIN
    init; calc; writeln('NO ANSWER!')
  END.