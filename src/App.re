open BsReactNative;

let app = () =>
  <ReasonApollo.Provider client=Client.instance>
    <View>
      <TitleBar />
      <View>
        <GetPosts />
      </View>
    </View>
  </ReasonApollo.Provider>