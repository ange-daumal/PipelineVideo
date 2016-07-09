# PipelineVideo
Pipeline de traitement video en parallèle écrit en C++ à l'aide de TBB.

#TBB Pipeline Construct

In TBB, a pipeline is a series of filters. Each filter takes an input token
and produces an output token.

Pipeline object:  Container of filters
Filter object:    Processors of tokens. Could be serial or parallel

