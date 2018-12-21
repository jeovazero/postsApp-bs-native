open BsReactNative;

let styles = StyleSheet.create(Style.{
  "main": style([
    height(Pct(100.)),
    width(Pct(100.))
  ])
})

module Main = { 
  type state = {
    showForm: bool
  };

  type action =
    | ToggleShowForm;

  let component = ReasonReact.reducerComponent("Main");

  let make = _children => {
    ...component,
    initialState: () => { showForm: false },
    reducer: (action, state) => {
      switch(action){
      | ToggleShowForm => Update({showForm: !state.showForm})
      };
    },
    render: ({state, send}) => {
        <ReasonApollo.Provider client=Client.instance>
          <View style=styles##main>
            <TitleBar />
            <GetPosts />
            {
              state.showForm
              ? <Form onPost={ () => send(ToggleShowForm) }/>
              : <FloatButton onPress={ () => send(ToggleShowForm) }/>
            }
          </View>
        </ReasonApollo.Provider>
    }
  }
};

let app = () => <Main />